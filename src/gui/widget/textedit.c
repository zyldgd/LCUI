﻿/* ***************************************************************************
 * textedit.c -- textedit widget, used to allow user edit text.
 *
 * Copyright (C) 2016-2017 by Liu Chao <lc-soft@live.cn>
 *
 * This file is part of the LCUI project, and may only be used, modified, and
 * distributed under the terms of the GPLv2.
 *
 * (GPLv2 is abbreviation of GNU General Public License Version 2)
 *
 * By continuing to use, modify, or distribute this file you indicate that you
 * have read the license and understand and accept it fully.
 *
 * The LCUI project is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GPL v2 for more details.
 *
 * You should have received a copy of the GPLv2 along with this file. It is
 * usually in the LICENSE.TXT file, If not, see <http://www.gnu.org/licenses/>.
 * ****************************************************************************/

/* ****************************************************************************
 * textedit.c -- 文本编辑部件，用于让用户编辑文本。
 *
 * 版权所有 (C) 2016-2017 归属于 刘超 <lc-soft@live.cn>
 *
 * 这个文件是LCUI项目的一部分，并且只可以根据GPLv2许可协议来使用、更改和发布。
 *
 * (GPLv2 是 GNU通用公共许可证第二版 的英文缩写)
 *
 * 继续使用、修改或发布本文件，表明您已经阅读并完全理解和接受这个许可协议。
 *
 * LCUI 项目是基于使用目的而加以散布的，但不负任何担保责任，甚至没有适销性或特
 * 定用途的隐含担保，详情请参照GPLv2许可协议。
 *
 * 您应已收到附随于本文件的GPLv2许可协议的副本，它通常在LICENSE.TXT文件中，如果
 * 没有，请查看：<http://www.gnu.org/licenses/>.
 * ****************************************************************************/

//#define DEBUG
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/font.h>
#include <LCUI/input.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/textedit.h>
#include <LCUI/gui/widget/textcaret.h>
#include <LCUI/ime.h>

#define TBT_SIZE	512

enum TaskType {
	TASK_SET_TEXT,
	TASK_UPDATE,
	TASK_UPDATE_MASK,
	TASK_UPDATE_CARET,
	TASK_TOTAL
};

typedef struct LCUI_TextEditRec_ {
	LCUI_TextLayer layer_source;		/**< 实际文本层 */
	LCUI_TextLayer layer_mask;		/**< 屏蔽后的文本层 */
	LCUI_TextLayer layer_placeholder;	/**< 占位符的文本层 */
	LCUI_TextLayer layer;			/**< 当前使用的文本层 */
	LCUI_Widget scrollbars[2];		/**< 两个滚动条 */
	LCUI_Widget caret;			/**< 文本插入符 */
	LCUI_BOOL is_read_only;			/**< 是否只读 */
	LCUI_BOOL is_multiline_mode;		/**< 是否为多行模式 */
	LCUI_BOOL is_placeholder_shown;		/**< 是否已经显示占位符 */
	wchar_t *allow_input_char;		/**< 允许输入的字符 */
	wchar_t password_char;			/**< 屏蔽符的副本 */
	size_t text_block_size;			/**< 块大小 */
	LinkedList text_blocks;			/**< 文本块缓冲区 */
	LinkedList text_tags;			/**< 当前处理的标签列表 */
	LCUI_BOOL tasks[TASK_TOTAL];		/**< 待处理的任务 */
	LCUI_Mutex mutex;			/**< 互斥锁 */
} LCUI_TextEditRec, *LCUI_TextEdit;

enum TextBlockType {
	TBT_BEGIN,
	TBT_BODY,
	TBT_END
};

enum TextBlockAddType {
	TBAT_INSERT,
	TBAT_APPEND
};

enum TextBlockOwnerType {
	TBOT_SOURCE,
	TBOT_PLACEHOLDER
};

/** 文本块数据结构 */
typedef struct LCUI_TextBlockRec_ {
	int type;			/**< 文本块类型 */
	int owner;			/**< 所属的文本层 */
	int add_type;			/**< 指定该文本块的添加方式 */
	wchar_t *text;			/**< 文本块(段) */
	size_t length;			/**< 文本块的长度 */
} LCUI_TextBlockRec, *LCUI_TextBlock;

static struct LCUI_TextEditModule {
	int event_id;
	LCUI_WidgetPrototype prototype;
} self;

static const char *textedit_css = CodeToString(

textedit {
	min-width: 124px;
	min-height: 14px;
	background-color: #fff;
	border: 1px solid #eee;
	padding: 5px 10px;
	focusable: true;
	display: inline-block;
}
textedit:focus {
	border: 1px solid #2196F3;
	box-shadow: 0 0 6px rgba(33,150,243,0.4);
}

textedit:disabled {
	opacity: 0.45;
}

);

static void fillchar( wchar_t *str, wchar_t ch )
{
	if( str ) {
		wchar_t *p;
		for( p = str; *p; ++p ) {
			*p = ch;
		}
	}
}

static void TextEdit_UpdateCaret( LCUI_Widget widget )
{
	LCUI_Pos pos;
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	float height, x = 0, y = 0, offset_x = 0, offset_y = 0;
	int row = edit->layer->insert_y;

	if( !edit->is_placeholder_shown ) {
		if( TextLayer_GetCaretPixelPos( edit->layer, &pos ) != 0 ) {
			return;
		}
		x = 1.0f * pos.x;
		y = 1.0f * pos.y;
	}
	height = (float)TextLayer_GetRowHeight( edit->layer, row );
	Widget_SetStyle( edit->caret, key_height, height, px );
	if( x > widget->box.content.width ) {
		offset_x = widget->box.content.width - x;
		offset_x -= edit->caret->width;
		x += offset_x;
	}
	if( y > widget->box.content.height ) {
		offset_y = widget->box.content.height - y;
		offset_y -= edit->caret->height;
		y += offset_y;
	}
	x += widget->padding.left;
	y += widget->padding.top;
	if( edit->layer->offset_x != offset_x ||
	    edit->layer->offset_y != offset_y ) {
		int ix = (int)offset_x;
		int iy = (int)offset_y;
		TextLayer_SetOffset( edit->layer, ix, iy );
		edit->tasks[TASK_UPDATE] = TRUE;
		Widget_AddTask( widget, WTT_USER );
	}
	Widget_Move( edit->caret, x, y );
	TextCaret_BlinkShow( edit->caret );
	if( edit->password_char ) {
		TextLayer_SetCaretPos( edit->layer_source, 
				       edit->layer->insert_y, 
				       edit->layer->insert_x );
	}
}

/** 移动文本框内的文本插入符的行列坐标 */
static void TextEdit_MoveCaret( LCUI_Widget widget, int row, int col )
{
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	if( edit->is_placeholder_shown ) {
		row = col = 0;
	}
	TextLayer_SetCaretPos( edit->layer, row, col );
	TextEdit_UpdateCaret( widget );
}

/*------------------------------- TextBlock ---------------------------------*/
static void TextBlock_OnDestroy( void *arg )
{
	LCUI_TextBlock blk = arg;
	free( blk->text );
	blk->text = NULL;
	free( blk );
}

static int TextEdit_AddTextToBuffer( LCUI_Widget widget, const wchar_t *wtext,
				     int add_type, int owner )
{
	const wchar_t *p;
	LCUI_TextEdit edit;
	LCUI_TextBlock txtblk;
	size_t i, j, len, tag_len, size;

	if( !wtext ) {
		return -1;
	}
	len = wcslen( wtext );
	edit = Widget_GetData( widget, self.prototype );
	for( i = 0; i < len; ++i ) {
		txtblk = NEW( LCUI_TextBlockRec, 1 );
		if( !txtblk ) {
			return -ENOMEM;
		}
		txtblk->owner = owner;
		txtblk->add_type = add_type;
		size = edit->text_block_size;
		if( i == 0 ) {
			txtblk->type = TBT_BEGIN;
		} else if( len - i > edit->text_block_size ) {
			txtblk->type = TBT_BODY;
		} else {
			size = len - i;
			txtblk->type = TBT_END;
		}
		txtblk->text = NEW( wchar_t, size );
		if( !txtblk->text ) {
			return -ENOMEM;
		}
		/* 如果未启用样式标签功能 */
		if( !edit->layer->is_using_style_tags ) {
			for( j = 0; i < len && j < size - 1; ++j, ++i ) {
				txtblk->text[j] = wtext[i];
			}
			--i;
			txtblk->text[j] = 0;
			txtblk->length = j;
			LinkedList_Append( &edit->text_blocks, txtblk );
			continue;
		}
		for( j = 0; i < len && j < size - 1; ++j, ++i ) {
			wchar_t *text;
			txtblk->text[j] = wtext[i];
			/* 检测是否有样式标签 */
			p = ScanStyleTag( wtext + i, NULL, 0, NULL );
			if( !p ) {
				p = ScanStyleEndingTag( wtext + i, NULL );
				if( !p ) {
					continue;
				}
			}
			/* 计算标签的长度 */
			tag_len = p - wtext - i;
			/* 若当前块大小能够容纳这个标签 */
			if( j + tag_len <= size - 1 ) {
				continue;
			}
			/* 重新计算该文本块的大小，并重新分配内存空间 */
			size = j + tag_len + 1;
			text = realloc( txtblk->text, sizeof( wchar_t ) * size );
			if( !text ) {
				return -ENOMEM;
			}
			txtblk->text = text;
		}
		--i;
		txtblk->text[j] = 0;
		txtblk->length = j;
		/* 添加文本块至缓冲区 */
		LinkedList_Append( &edit->text_blocks, txtblk );
	}
	edit->tasks[TASK_SET_TEXT] = TRUE;
	Widget_AddTask( widget, WTT_USER );
	return 0;
}

/** 更新文本框内的字体位图 */
static void TextEdit_ProcTextBlock( LCUI_Widget widget, LCUI_TextBlock txtblk )
{
	LinkedList *tags;
	LCUI_TextEdit edit;
	LCUI_TextLayer layer;
	edit = Widget_GetData( widget, self.prototype );
	switch( txtblk->owner ) {
	case TBOT_SOURCE:
		layer = edit->layer_source;
		tags = &edit->text_tags;
		break;
	case TBOT_PLACEHOLDER:
		layer = edit->layer_placeholder;
		tags = NULL;
		break;
	default:return;
	}
	switch( txtblk->add_type ) {
	case TBAT_APPEND:
		/* 将此文本块追加至文本末尾 */
		TextLayer_AppendTextW( layer, txtblk->text, tags );
		break;
	case TBAT_INSERT:
		/* 将此文本块插入至文本插入符所在处 */
		TextLayer_InsertTextW( layer, txtblk->text, tags );
	default: break;
	}
	if( edit->password_char && txtblk->owner == TBOT_SOURCE ) {
		wchar_t *text = NEW( wchar_t, txtblk->length + 1 );
		wcsncpy( text, txtblk->text, txtblk->length + 1 );
		fillchar( text, edit->password_char );
		layer = edit->layer_mask;
		if( txtblk->add_type == TBAT_INSERT ) {
			TextLayer_InsertTextW( layer, text, NULL );
		} else {
			TextLayer_AppendTextW( layer, text, NULL );
		}
		free( text );
	}
}


/** 更新文本框的文本图层 */
static void TextEdit_UpdateTextLayer( LCUI_Widget widget )
{
	LinkedList rects;
	LCUI_TextEdit edit;
	LCUI_TextStyle style;
	LinkedListNode *node;
	LinkedList_Init( &rects );
	edit = Widget_GetData( widget, self.prototype );
	TextStyle_Copy( &style, &edit->layer_source->text_style );
	if( edit->password_char ) {
		TextLayer_SetTextStyle( edit->layer_mask, &style );
	}
	style.has_fore_color = TRUE;
	style.fore_color = RGB(140, 140, 140);
	TextLayer_SetTextStyle( edit->layer_placeholder, &style );
	TextStyle_Destroy( &style );
	TextLayer_Update( edit->layer, &rects );
	for( LinkedList_Each( node, &rects ) ) {
		Widget_InvalidateArea( widget, node->data, SV_CONTENT_BOX );
	}
	TextLayer_ClearInvalidRect( edit->layer );
	RectList_Clear( &rects );
}

static void TextEdit_OnTask( LCUI_Widget widget )
{
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	while( edit->tasks[TASK_UPDATE_MASK] ) {
		int i, len;
		wchar_t text[256];
		edit->tasks[TASK_UPDATE] = TRUE;
		edit->tasks[TASK_UPDATE_MASK] = FALSE;
		TextLayer_ClearText( edit->layer_mask );
		if( !edit->password_char ) {
			edit->layer = edit->layer_source;
			break;
		}
		edit->layer = edit->layer_mask;
		len = TextEdit_GetTextLength( widget );
		for( i = 0; i < len; i += 255 ) {
			TextEdit_GetTextW( widget, i, 255, text );
			fillchar( text, edit->password_char );
			TextLayer_AppendTextW( edit->layer, text, NULL );
		}
	}
	if( edit->tasks[TASK_SET_TEXT] ) {
		LinkedList blocks;
		LinkedListNode *node;
		LCUI_WidgetEventRec ev;
		LinkedList_Init( &blocks );
		LCUIMutex_Lock( &edit->mutex );
		LinkedList_Concat( &blocks, &edit->text_blocks );
		LCUIMutex_Unlock( &edit->mutex );
		for( LinkedList_Each( node, &blocks ) ) {
			TextEdit_ProcTextBlock( widget, node->data );
		}
		LinkedList_Clear( &blocks, TextBlock_OnDestroy );
		ev.type = self.event_id;
		ev.cancel_bubble = TRUE;
		Widget_TriggerEvent( widget, &ev, NULL );
		edit->tasks[TASK_SET_TEXT] = FALSE;
		edit->tasks[TASK_UPDATE] = TRUE;
	}
	if( edit->tasks[TASK_UPDATE] ) {
		LCUI_BOOL is_shown;
		is_shown = edit->layer_source->length == 0;
		if( is_shown ) {
			edit->layer = edit->layer_placeholder;
		} else if( edit->password_char ) {
			edit->layer = edit->layer_mask;
		} else {
			edit->layer = edit->layer_source;
		}
		TextEdit_UpdateTextLayer( widget );
		if( edit->is_placeholder_shown != is_shown ) {
			Widget_InvalidateArea( widget, NULL, SV_PADDING_BOX );
		}
		edit->is_placeholder_shown = is_shown;
		edit->tasks[TASK_UPDATE_CARET] = TRUE;
		edit->tasks[TASK_UPDATE] = FALSE;
	}
	if( edit->tasks[TASK_UPDATE_CARET] ) {
		edit->tasks[TASK_UPDATE_CARET] = FALSE;
		TextEdit_UpdateCaret( widget );
	}
}

static void TextEdit_AutoSize( LCUI_Widget widget,
			       float *width, float *height )
{
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	if( edit->is_multiline_mode ) {
		int i, n, h = 0;
		n = max( TextLayer_GetRowTotal( edit->layer ), 3);
		for( i = 0; i < n; ++i ) {
			h += TextLayer_GetRowHeight( edit->layer, i );
		}
		*height = 1.0f * h;
	} else {
		*height = TextLayer_GetHeight( edit->layer ) * 1.0f;
	}
	*width = 176.0;
}

/*----------------------------- End TextBlock ---------------------------------*/

/** 指定文本框是否处理控制符 */
void TextEdit_SetUsingStyleTags( LCUI_Widget widget, LCUI_BOOL is_true )
{
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	TextLayer_SetUsingStyleTags( edit->layer, is_true );
}

/** 指定文本框是否启用多行文本显示 */
void TextEdit_SetMultiline( LCUI_Widget widget, LCUI_BOOL is_true )
{
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	TextLayer_SetMultiline( edit->layer_placeholder, is_true );
	TextLayer_SetMultiline( edit->layer_source, is_true );
	TextLayer_SetMultiline( edit->layer_mask, is_true );
	edit->is_multiline_mode = is_true;
}

void TextEdit_ClearText( LCUI_Widget widget )
{
	LCUI_TextEdit edit;
	edit = Widget_GetData( widget, self.prototype );
	LCUIMutex_Lock( &edit->mutex );
	TextLayer_ClearText( edit->layer_source );
	StyleTags_Clear( &edit->text_tags );
	edit->tasks[TASK_UPDATE] = TRUE;
	Widget_AddTask( widget, WTT_USER );
	LCUIMutex_Unlock( &edit->mutex );
	Widget_InvalidateArea( widget, NULL, SV_PADDING_BOX );
}

int TextEdit_GetTextW( LCUI_Widget w, int start, int max_len, wchar_t *buf )
{
	LCUI_TextEdit edit = Widget_GetData( w, self.prototype );
	return TextLayer_GetTextW( edit->layer_source, start, max_len, buf );
}

int TextEdit_GetTextLength( LCUI_Widget w )
{
	LCUI_TextEdit edit = Widget_GetData( w, self.prototype );
	return edit->layer_source->length;
}

int TextEdit_SetTextW( LCUI_Widget w, const wchar_t *wstr )
{
	TextEdit_ClearText( w );
	return TextEdit_AddTextToBuffer( w, wstr, TBAT_APPEND, TBOT_SOURCE );
}

int TextEdit_SetText( LCUI_Widget widget, const char *utf8_str )
{
	int ret;
	size_t len = strlen( utf8_str ) + 1;
	wchar_t *wstr = malloc( len * sizeof( wchar_t ) );
	if( !wstr ) {
		return -ENOMEM;
	}
	LCUI_DecodeString( wstr, utf8_str, (int)len, ENCODING_UTF8 );
	ret = TextEdit_SetTextW( widget, wstr );
	free( wstr );
	return ret;
}

void TextEdit_SetPasswordChar( LCUI_Widget w, wchar_t ch )
{
	LCUI_TextEdit edit = Widget_GetData( w, self.prototype );
	edit->password_char = ch;
	edit->tasks[TASK_UPDATE_MASK] = TRUE;
	Widget_AddTask( w, WTT_USER );
}

/** 为文本框追加文本（宽字符版） */
int TextEdit_AppendTextW( LCUI_Widget w, const wchar_t *wstr )
{
	return TextEdit_AddTextToBuffer( w, wstr, TBAT_APPEND, TBOT_SOURCE );
}

/** 为文本框插入文本（宽字符版） */
int TextEdit_InsertTextW( LCUI_Widget w, const wchar_t *wstr )
{
	return TextEdit_AddTextToBuffer( w, wstr, TBAT_INSERT, TBOT_SOURCE );
}

int TextEdit_SetPlaceHolderW( LCUI_Widget w, const wchar_t *wstr )
{
	LCUI_TextEdit edit = Widget_GetData( w, self.prototype );
	LCUIMutex_Lock( &edit->mutex );
	TextLayer_ClearText( edit->layer_placeholder );
	LCUIMutex_Unlock( &edit->mutex );
	if( edit->is_placeholder_shown ) {
		Widget_InvalidateArea( w, NULL, SV_PADDING_BOX );
	}
	return TextEdit_AddTextToBuffer( w, wstr, TBAT_INSERT, 
					 TBOT_PLACEHOLDER );
}

int TextEdit_SetPlaceHolder( LCUI_Widget w, const char *str )
{
	int ret;
	size_t len = strlen( str ) + 1;
	wchar_t *wstr = malloc( len * sizeof( wchar_t ) );
	if( !wstr ) {
		return -ENOMEM;
	}
	LCUI_DecodeString( wstr, str, (int)len, ENCODING_UTF8 );
	ret = TextEdit_SetPlaceHolderW( w, wstr );
	free( wstr );
	return ret;
}

void TextEdit_SetCaretBlink( LCUI_Widget w, LCUI_BOOL enabled, int time )
{
	LCUI_TextEdit edit = Widget_GetData( w, self.prototype );
	TextCaret_SetVisible( edit->caret, enabled );
	TextCaret_SetBlinkTime( edit->caret, time ); 
}

static void TextEdit_OnParseText( LCUI_Widget w, const char *text )
{
	TextEdit_SetText( w, text );
}

static void TextEdit_OnFocus( LCUI_Widget widget, LCUI_WidgetEvent e, void *arg )
{
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	TextCaret_SetVisible( edit->caret, TRUE );
	TextCaret_BlinkHide( edit->caret );
	edit->tasks[TASK_UPDATE_CARET] = TRUE;
	Widget_AddTask( widget, WTT_USER );
}

static void TextEdit_OnBlur( LCUI_Widget widget, LCUI_WidgetEvent e, void *arg )
{
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	TextCaret_SetVisible( edit->caret, FALSE );
}

static void TextEdit_TextBackspace( LCUI_Widget widget, int n_ch )
{
	LCUI_TextEdit edit;
	LCUI_WidgetEventRec ev;
	edit = Widget_GetData( widget, self.prototype );
	LCUIMutex_Lock( &edit->mutex );
	TextLayer_TextBackspace( edit->layer_source, n_ch );
	if( edit->password_char ) {
		TextLayer_TextBackspace( edit->layer_mask, n_ch );
	}
	TextCaret_BlinkShow( edit->caret );
	edit->tasks[TASK_UPDATE] = TRUE;
	Widget_AddTask( widget, WTT_USER );
	LCUIMutex_Unlock( &edit->mutex );
	ev.type = self.event_id;
	ev.cancel_bubble = TRUE;
	Widget_TriggerEvent( widget, &ev, NULL );
}

static void TextEdit_TextDelete(LCUI_Widget widget, int n_ch )
{
	LCUI_TextEdit edit;
	LCUI_WidgetEventRec ev;
	edit = Widget_GetData( widget, self.prototype );
	LCUIMutex_Lock( &edit->mutex );
	TextLayer_TextDelete( edit->layer_source, n_ch );
	if( edit->password_char ) {
		TextLayer_TextDelete( edit->layer_mask, n_ch );
	}
	TextCaret_BlinkShow( edit->caret );
	edit->tasks[TASK_UPDATE] = TRUE;
	Widget_AddTask( widget, WTT_USER );
	LCUIMutex_Unlock( &edit->mutex );
	ev.type = self.event_id;
	ev.cancel_bubble = TRUE;
	Widget_TriggerEvent( widget, &ev, NULL );
}

/** 处理按键事件 */
static void TextEdit_OnKeyDown( LCUI_Widget widget, LCUI_WidgetEvent e, void *arg )
{
	int cols, rows, cur_col, cur_row;
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	cur_row = edit->layer->insert_y;
	cur_col = edit->layer->insert_x;
	rows = TextLayer_GetRowTotal( edit->layer );
	cols = TextLayer_GetRowTextLength( edit->layer, cur_row );
	switch( e->key.code ) {
	case LCUIKEY_HOME: // home键移动光标至行首
		cur_col = 0;
		break;
	case LCUIKEY_END: // end键移动光标至行尾
		cur_col = cols;
		break;
	case LCUIKEY_LEFT:
		if( cur_col > 0 ) {
			--cur_col;
		} else if( cur_row > 0 ) {
			--cur_row;
			cur_col = TextLayer_GetRowTextLength( edit->layer,
							      cur_row );
		}
		break;
	case LCUIKEY_RIGHT:
		if( cur_col < cols ) {
			++cur_col;
		} else if( cur_row < rows - 1 ) {
			++cur_row;
			cur_col = 0;
		}
		break;
	case LCUIKEY_UP:
		if( cur_row > 0 ) {
			--cur_row;
		}
		break;
	case LCUIKEY_DOWN:
		if( cur_row < rows - 1 ) {
			++cur_row;
		}
		break;
	case LCUIKEY_BACKSPACE: // 删除光标左边的字符
		TextEdit_TextBackspace( widget, 1 );
		return;
	case LCUIKEY_DELETE: // 删除光标右边的字符
		TextEdit_TextDelete( widget, 1 );
		return;
	default:break;
	}
	TextEdit_MoveCaret( widget, cur_row, cur_col );
}

/** 处理输入法对文本框输入的内容 */
static void TextEdit_OnTextInput( LCUI_Widget widget, 
				  LCUI_WidgetEvent e, void *arg )
{
	uint_t i, j, k;
	wchar_t ch, *text, excludes[8] = L"\b\r\t\x1b";
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	/* 如果不是多行文本编辑模式则删除换行符 */
	if( !edit->is_multiline_mode ) {
		wcscat( excludes, L"\n" );
	}
	/* 如果文本框是只读的 */
	if( edit->is_read_only ) {
		return;
	}
	text = malloc( sizeof( wchar_t ) * (e->text.length + 1) );
	if( !text ) {
		return;
	}
	for( i = 0, j = 0; i < e->text.length; ++i ) {
		ch = e->text.text[i];
		for( k = 0; excludes[k]; ++k ) {
			if( ch == excludes[k] ) {
				break;
			}
		}
		if( excludes[k] ) {
			continue;
		}
		if( !edit->allow_input_char ) {
			text[j++] = ch;
			continue;
		}
		/* 判断当前字符是否为限制范围内的字符 */
		for( j = 0; edit->allow_input_char[j]; ++j ) {
			if( edit->allow_input_char[j] == ch ) {
				break;
			}
		}
		/* 如果已提前结束循环，则表明当前字符是允许的 */
		if( edit->allow_input_char[j] ) {
			text[j++] = e->text.text[i];
			continue;
		}
		text[j] = 0;
	}
	text[j] = 0;
	TextEdit_InsertTextW( widget, text );
	free( text );
}

static void TextEdit_OnResize( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	int iw, ih;
	LinkedList rects;
	LinkedListNode *node;
	float width = 0, height = 0;
	float max_width = 0, max_height = 0;
	LCUI_TextEdit edit = Widget_GetData( w, self.prototype );
	if( !w->style->sheet[key_width].is_valid ||
	    w->style->sheet[key_width].type == SVT_AUTO ) {
		max_width = Widget_ComputeMaxWidth( w );
		max_width -= w->computed_style.border.left.width;
		max_width -= w->computed_style.border.right.width;
		max_width -= w->padding.left + w->padding.right;
	} else {
		max_width = width = w->box.content.width;
	}
	if( w->style->sheet[key_height].is_valid &&
	    w->style->sheet[key_height].type != SVT_AUTO ) {
		max_height = height = w->box.content.width;
	}
	LinkedList_Init( &rects );
	iw = roundi( width );
	ih = roundi( height );
	TextLayer_SetFixedSize( edit->layer_mask, iw, ih );
	TextLayer_SetFixedSize( edit->layer_source, iw, ih );
	TextLayer_SetFixedSize( edit->layer_placeholder, iw, ih );
	iw = roundi( max_width );
	ih = roundi( max_height );
	TextLayer_SetMaxSize( edit->layer_mask, iw, ih );
	TextLayer_SetMaxSize( edit->layer_source, iw, ih );
	TextLayer_SetMaxSize( edit->layer_placeholder, iw, ih );
	TextLayer_Update( edit->layer, &rects );
	for( LinkedList_Each( node, &rects ) ) {
		Widget_InvalidateArea( w, node->data, SV_CONTENT_BOX );
	}
	RectList_Clear( &rects );
	TextLayer_ClearInvalidRect( edit->layer );
}

static void TextEdit_OnMouseMove( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	int x, y;
	float offset_x, offset_y;
	LCUI_TextEdit edit = Widget_GetData( w, self.prototype );
	if( !edit->is_placeholder_shown ) {
		Widget_GetOffset( w, NULL, &offset_x, &offset_y );
		x = e->motion.x - roundi( offset_x + w->padding.left );
		y = e->motion.y - roundi( offset_y + w->padding.top );
		TextLayer_SetCaretPosByPixelPos( edit->layer_source, x, y );
	}
	TextEdit_UpdateCaret( w );
}

static void TextEdit_OnMouseUp( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	Widget_ReleaseMouseCapture( w );
	Widget_UnbindEvent( w, "mousemove", TextEdit_OnMouseMove );
}

static void TextEdit_OnMouseDown( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	int x, y;
	float offset_x, offset_y;
	LCUI_TextEdit edit = Widget_GetData( w, self.prototype );
	Widget_GetOffset( w, NULL, &offset_x, &offset_y );
	x = e->motion.x - roundi( offset_x + w->padding.left );
	y = e->motion.y - roundi( offset_y + w->padding.top );
	TextLayer_SetCaretPosByPixelPos( edit->layer, x, y );
	TextEdit_UpdateCaret( w );
	Widget_SetMouseCapture( w );
	Widget_BindEvent( w, "mousemove", TextEdit_OnMouseMove, NULL, NULL );
}

static void TextEdit_OnReady( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	TextEdit_UpdateCaret( w );
}

static void TextEdit_SetAttr( LCUI_Widget w, const char *name, 
			      const char *val )
{
	if( strcasecmp( name, "data-placeholder" ) == 0 ) {
		TextEdit_SetPlaceHolder( w, val );
	}
}

static void TextEdit_OnInit( LCUI_Widget w )
{
	LCUI_TextEdit edit;
	const size_t data_size = sizeof( LCUI_TextEditRec );
	edit = Widget_AddData( w, self.prototype, data_size );
	edit->is_read_only = FALSE;
	edit->password_char = 0;
	edit->allow_input_char = NULL;
	edit->is_placeholder_shown = FALSE;
	edit->layer_mask = TextLayer_New();
	edit->layer_source = TextLayer_New();
	edit->layer_placeholder = TextLayer_New();
	edit->layer = edit->layer_source;
	edit->text_block_size = TBT_SIZE;
	edit->caret = LCUIWidget_New( "textcaret" );
	w->computed_style.focusable = TRUE;
	memset( edit->tasks, 0, sizeof( edit->tasks ) );
	LinkedList_Init( &edit->text_blocks );
	StyleTags_Init( &edit->text_tags );
	TextEdit_SetMultiline( w, FALSE );
	TextLayer_SetAutoWrap( edit->layer, TRUE );
	TextLayer_SetAutoWrap( edit->layer_mask, TRUE );
	TextLayer_SetUsingStyleTags( edit->layer, FALSE );
	Widget_BindEvent( w, "textinput", TextEdit_OnTextInput, NULL, NULL );
	Widget_BindEvent( w, "mousedown", TextEdit_OnMouseDown, NULL, NULL );
	Widget_BindEvent( w, "mouseup", TextEdit_OnMouseUp, NULL, NULL );
	Widget_BindEvent( w, "keydown", TextEdit_OnKeyDown, NULL, NULL );
	Widget_BindEvent( w, "resize", TextEdit_OnResize, NULL, NULL );
	Widget_BindEvent( w, "focus", TextEdit_OnFocus, NULL, NULL );
	Widget_BindEvent( w, "blur", TextEdit_OnBlur, NULL, NULL );
	Widget_BindEvent( w, "ready", TextEdit_OnReady, NULL, NULL );
	Widget_Append( w, edit->caret );
	Widget_Hide( edit->caret );
	LCUIMutex_Init( &edit->mutex );
}

static void TextEdit_OnDestroy( LCUI_Widget widget )
{
	LCUI_TextEdit edit = Widget_GetData( widget, self.prototype );
	edit->layer = NULL;
	TextLayer_Destroy( edit->layer_source );
	TextLayer_Destroy( edit->layer_placeholder );
	TextLayer_Destroy( edit->layer_mask );
	LinkedList_Clear( &edit->text_blocks, TextBlock_OnDestroy );
}

static void TextEdit_OnPaint( LCUI_Widget w, LCUI_PaintContext paint )
{
	LCUI_Pos layer_pos;
	LCUI_Rect content_rect, rect;
	LCUI_TextEdit edit = Widget_GetData( w, self.prototype );
	content_rect.width = roundi( w->box.content.width );
	content_rect.height = roundi( w->box.content.height );
	content_rect.y = (int)(w->box.content.y - w->box.graph.y + 0.5);
	content_rect.x = (int)(w->box.content.x - w->box.graph.x + 0.5);
	LCUIRect_GetOverlayRect( &content_rect, &paint->rect, &rect );
	layer_pos.x = content_rect.x - paint->rect.x;
	layer_pos.y = content_rect.y - paint->rect.y;
	rect.x -= content_rect.x;
	rect.y -= content_rect.y;
	TextLayer_DrawToGraph( edit->layer, rect, layer_pos, &paint->canvas );
}

/** 添加 TextEdit 部件类型 */
void LCUIWidget_AddTextEdit( void )
{
	self.prototype = LCUIWidget_NewPrototype( "textedit", NULL );
	self.prototype->init = TextEdit_OnInit;
	self.prototype->paint = TextEdit_OnPaint;
	self.prototype->destroy = TextEdit_OnDestroy;
	self.prototype->settext = TextEdit_OnParseText;
	self.prototype->setattr = TextEdit_SetAttr;
	self.prototype->autosize = TextEdit_AutoSize;
	self.prototype->runtask = TextEdit_OnTask;
	self.event_id = LCUIWidget_AllocEventId();
	LCUIWidget_SetEventName( self.event_id, "change" );
	LCUI_LoadCSSString( textedit_css, __FILE__ );
}
