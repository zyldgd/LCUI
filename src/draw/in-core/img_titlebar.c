/* ***************************************************************************
 * titlebar.c -- window titlebar graphic resources
 * 
 * Copyright (C) 2012 by
 * Liu Chao
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
 * titlebar.c -- 窗口标题栏图形资源
 *
 * 版权所有 (C) 2012 归属于 
 * 刘超
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

#include <LCUI_Build.h>
#include LC_LCUI_H
#include LC_GRAPH_H
#include LC_MEM_H

#include <stdio.h>
#include <string.h>

LCUI_EXPORT(int) Load_Graph_Default_TitleBar_CloseBox_Normal(LCUI_Graph *pic)
/* 功能：载入图形，该图形为标题栏上的关闭按钮，按钮为正常状态 */
{
	unsigned char red[]={
		255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,242,213,184,177,184,213,230,213,184,177,184,213,242,255,255,255,255,
		255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,227,173,126,108,110,133,152,133,110,108,
		126,173,227,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,207,140,255,
		255,255,80,85,80,255,255,255,140,207,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,
		255,255,255,255,223,145,90,255,255,255,57,255,255,255,90,145,223,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,
		255,255,255,255,255,255,255,255,255,255,255,237,175,114,74,255,255,255,255,255,74,114,175,237,255,255,255,255,255,255,255,255,
		255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,233,156,86,55,255,255,255,55,86,156,233,255,255,
		255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,232,152,83,55,253,253,
		253,55,83,152,232,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,
		228,149,89,60,244,244,244,244,244,60,89,149,228,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,
		255,255,255,255,255,255,255,200,108,66,232,232,232,45,232,232,232,66,108,200,255,255,255,255,255,255,255,255,255,255,255,255,
		0,0,255,255,255,255,255,255,255,255,255,255,255,255,165,90,220,220,220,53,55,53,220,220,220,90,165,255,255,255,255,255,
		255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,175,99,63,56,56,66,78,66,56,56,63,
		99,175,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,199,135,98,92,
		98,135,168,135,98,92,98,135,199,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,0};

	unsigned char green[]={
		255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,244,219,195,187,195,219,233,219,195,187,195,219,244,255,255,255,255,
		255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,231,185,144,128,130,149,166,149,130,128,
		144,185,231,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,213,156,255,
		255,255,104,108,104,255,255,255,156,213,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,
		255,255,255,255,227,160,112,255,255,255,85,255,255,255,112,160,227,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,
		255,255,255,255,255,255,255,255,255,255,255,239,186,133,99,255,255,255,255,255,99,133,186,239,255,255,255,255,255,255,255,255,
		255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,236,169,109,83,255,255,255,83,109,169,236,255,255,
		255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,236,166,107,83,253,253,
		253,83,107,166,236,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,
		231,163,112,86,246,246,246,246,246,86,112,163,231,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,
		255,255,255,255,255,255,255,208,129,92,235,235,235,74,235,235,235,92,129,208,255,255,255,255,255,255,255,255,255,255,255,255,
		0,0,255,255,255,255,255,255,255,255,255,255,255,255,177,112,225,225,225,81,83,81,225,225,225,112,177,255,255,255,255,255,
		255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,186,121,89,83,83,92,102,92,83,83,89,
		121,186,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,207,151,120,115,
		120,151,180,151,120,115,120,151,207,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,0};

	unsigned char blue[]={
		255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,245,223,202,195,202,223,236,223,202,195,202,223,245,255,255,255,255,
		255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,234,192,156,143,145,162,176,162,145,143,
		156,192,234,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,219,167,255,
		255,255,121,125,121,255,255,255,167,219,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,
		255,255,255,255,230,170,128,255,255,255,104,255,255,255,128,170,230,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,
		255,255,255,255,255,255,255,255,255,255,255,241,194,147,116,255,255,255,255,255,116,147,194,241,255,255,255,255,255,255,255,255,
		255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,239,179,125,103,255,255,255,103,125,179,239,255,255,
		255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,237,176,124,103,253,253,
		253,103,124,176,237,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,
		235,174,128,105,247,247,247,247,247,105,128,174,235,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,
		255,255,255,255,255,255,255,213,143,110,238,238,238,94,238,238,238,110,143,213,255,255,255,255,255,255,255,255,255,255,255,255,
		0,0,255,255,255,255,255,255,255,255,255,255,255,255,185,129,229,229,229,100,103,100,229,229,229,129,185,255,255,255,255,255,
		255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,194,135,109,103,103,111,119,111,103,103,109,
		135,194,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,212,163,135,130,
		135,163,188,163,135,130,135,163,212,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,0};

	unsigned char alpha[]={
		0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,34,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
		30,30,30,30,30,30,30,30,30,30,30,30,18,56,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,
		80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,30,55,58,29,29,29,29,29,29,29,29,29,29,
		29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,58,29,51,55,27,27,27,
		27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,
		55,27,49,52,26,26,26,26,26,26,26,26,26,26,26,27,31,36,37,36,31,29,31,36,37,36,31,27,26,26,26,26,
		26,26,26,26,26,26,26,52,26,46,47,23,23,23,23,23,23,23,23,23,23,23,27,35,49,58,56,46,40,46,56,58,
		49,35,27,23,23,23,23,23,23,23,23,23,23,23,47,24,42,44,22,22,22,22,22,22,22,22,22,22,22,26,41,208,
		208,208,75,68,75,208,208,208,41,26,22,22,22,22,22,22,22,22,22,22,22,44,22,40,38,19,19,19,19,19,19,19,
		19,19,19,19,22,34,59,208,208,208,102,208,208,208,59,34,22,19,19,19,19,19,19,19,19,19,19,19,38,21,37,38,
		18,18,18,18,18,18,18,18,18,18,18,20,27,45,73,208,208,208,208,208,73,45,27,20,18,18,18,18,18,18,18,18,
		18,18,18,38,19,33,32,15,15,15,15,15,15,15,15,15,15,15,15,17,25,50,85,207,207,207,85,50,25,17,15,15,
		15,15,15,15,15,15,15,15,15,15,32,17,29,31,14,14,14,14,14,14,14,14,14,14,14,14,16,25,49,85,207,207,
		207,85,49,25,16,14,14,14,14,14,14,14,14,14,14,14,14,31,15,27,29,12,12,12,12,12,12,12,12,12,12,12,
		13,20,38,68,206,206,206,206,206,68,38,20,13,12,12,12,12,12,12,12,12,12,12,12,29,14,21,23,10,10,10,10,
		10,10,10,10,10,10,10,13,26,52,206,206,206,96,206,206,206,52,26,13,10,10,10,10,10,10,10,10,10,10,10,23,
		11,20,22,8,8,8,8,8,8,8,8,8,8,8,14,28,206,206,206,65,58,65,206,206,206,28,14,8,8,8,8,8,
		8,8,8,8,8,8,22,10,16,20,6,6,6,6,6,6,6,6,6,6,6,9,19,33,43,41,30,23,30,41,43,33,
		19,9,6,6,6,6,6,6,6,6,6,6,6,20,8,12,16,5,5,5,5,5,5,5,5,5,5,5,7,11,16,18,
		16,11,8,11,16,18,16,11,7,5,5,5,5,5,5,5,5,5,5,5,16,6,10,12,3,3,3,3,3,3,3,3,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,12,5,7,8,2,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,8,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,2};

	int value;
	if(Graph_Valid(pic))
	{
		Graph_Free(pic);
	}
	Graph_Init(pic);
	pic->have_alpha = IS_TRUE;
	pic->alpha = 255; 
	value = Graph_Create(pic, 39, 20); 
	if(value == 0)
	{ 
		memcpy(pic->rgba[0], red, sizeof(red)); 
		memcpy(pic->rgba[1], green, sizeof(green)); 
		memcpy(pic->rgba[2], blue, sizeof(blue)); 
		memcpy(pic->rgba[3], alpha, sizeof(alpha)); 
	} 
	return value;
}

LCUI_EXPORT(int) Load_Graph_Default_TitleBar_CloseBox_HighLight(LCUI_Graph *pic)
/* 功能：载入图形，该图形为标题栏上的关闭按钮，按钮为高亮状态 */
{
	unsigned char red[]={
		255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,26,248,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,0,40,250,244,244,244,244,244,244,244,244,244,244,
		244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,251,0,43,251,244,244,244,
		244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,
		251,0,42,251,244,244,244,244,244,244,244,244,244,244,244,243,242,239,238,239,242,243,242,239,238,239,242,243,244,244,244,244,
		244,244,244,244,244,244,244,251,0,41,250,244,244,244,244,244,244,244,244,244,244,244,242,238,231,227,228,232,235,232,228,227,
		231,238,242,244,244,244,244,244,244,244,244,244,244,244,250,0,42,250,244,244,244,244,244,244,244,244,244,244,244,241,234,255,
		255,255,218,221,218,255,255,255,234,241,244,244,244,244,244,244,244,244,244,244,244,250,0,40,250,244,244,244,244,244,244,244,
		244,244,244,244,242,235,223,255,255,255,205,255,255,255,223,235,242,244,244,244,244,244,244,244,244,244,244,244,249,0,39,250,
		244,244,244,244,244,244,244,244,244,244,244,243,238,229,215,255,255,255,255,255,215,229,238,243,244,244,244,244,244,244,244,244,
		244,244,244,248,0,40,249,244,244,244,244,244,244,244,244,244,244,244,244,243,237,222,206,255,255,255,206,222,237,243,244,244,
		244,244,244,244,244,244,244,244,244,244,248,0,40,249,244,244,244,244,244,244,244,244,244,244,244,244,243,236,220,204,254,254,
		254,204,220,236,243,244,244,244,244,244,244,244,244,244,244,244,244,246,0,38,249,244,244,244,244,244,244,244,244,244,244,244,
		243,236,224,208,251,251,251,251,251,208,224,236,243,244,244,244,244,244,244,244,244,244,244,244,246,0,36,248,244,244,244,244,
		244,244,244,244,244,244,244,241,229,212,248,248,248,195,248,248,248,212,229,241,244,244,244,244,244,244,244,244,244,244,244,246,
		0,29,246,244,244,244,244,244,244,244,244,244,244,244,237,223,245,245,245,202,205,202,245,245,245,223,237,244,244,244,244,244,
		244,244,244,244,244,244,246,0,0,246,244,244,244,244,244,244,244,244,244,244,244,239,227,214,207,209,216,221,216,209,207,214,
		227,239,244,244,244,244,244,244,244,244,244,244,244,246,0,0,247,244,244,244,244,244,244,244,244,244,244,244,241,233,225,223,
		225,233,237,233,225,223,225,233,241,244,244,244,244,244,244,244,244,244,244,244,247,0,0,247,244,244,244,244,244,244,244,244,
		244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,247,0,0,247,244,
		244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,
		244,244,247,0,0,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,
		244,244,244,244,244,244,244,244,244,244,0};

	unsigned char green[]={
		255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,56,101,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,
		114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,114,90,0,86,99,55,55,55,55,55,55,55,55,55,55,
		55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,103,0,93,101,55,55,55,
		55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,
		103,0,91,100,55,55,55,55,55,55,55,55,55,55,55,55,54,54,54,54,54,55,54,54,54,54,54,55,55,55,55,55,
		55,55,55,55,55,55,55,100,0,89,98,55,55,55,55,55,55,55,55,55,55,55,55,54,52,51,51,52,53,52,51,51,
		52,54,55,55,55,55,55,55,55,55,55,55,55,55,98,0,91,99,55,55,55,55,55,55,55,55,55,55,55,54,53,255,
		255,255,49,49,49,255,255,255,53,54,55,55,55,55,55,55,55,55,55,55,55,99,0,88,98,55,55,55,55,55,55,55,
		55,55,55,55,55,53,50,255,255,255,46,255,255,255,50,53,55,55,55,55,55,55,55,55,55,55,55,55,93,0,84,98,
		55,55,55,55,55,55,55,55,55,55,55,55,54,51,48,255,255,255,255,255,48,51,54,55,55,55,55,55,55,55,55,55,
		55,55,55,92,0,86,95,55,55,55,55,55,55,55,55,55,55,55,55,55,53,50,46,255,255,255,46,50,53,55,55,55,
		55,55,55,55,55,55,55,55,55,55,92,0,88,95,55,55,55,55,55,55,55,55,55,55,55,55,55,53,49,45,254,254,
		254,45,49,53,55,55,55,55,55,55,55,55,55,55,55,55,55,84,0,83,98,55,55,55,55,55,55,55,55,55,55,55,
		55,53,50,46,252,252,252,252,252,46,50,53,55,55,55,55,55,55,55,55,55,55,55,55,88,0,79,93,55,55,55,55,
		55,55,55,55,55,55,55,54,51,47,249,249,249,43,249,249,249,47,51,54,55,55,55,55,55,55,55,55,55,55,55,86,
		0,63,91,55,55,55,55,55,55,55,55,55,55,55,53,50,247,247,247,45,45,45,247,247,247,50,53,55,55,55,55,55,
		55,55,55,55,55,55,91,0,0,99,55,55,55,55,55,55,55,55,55,55,55,54,51,48,46,46,48,49,48,46,46,48,
		51,54,55,55,55,55,55,55,55,55,55,55,55,99,0,0,100,55,55,55,55,55,55,55,55,55,55,55,54,52,50,50,
		50,52,53,52,50,50,50,52,54,55,55,55,55,55,55,55,55,55,55,55,100,0,0,108,55,55,55,55,55,55,55,55,
		55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,108,0,0,110,55,
		55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,
		55,55,110,0,0,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,
		55,55,55,55,55,55,55,55,55,55,0};

	unsigned char blue[]={
		255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,70,73,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,
		81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,60,0,108,64,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,68,0,117,65,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		68,0,115,65,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,65,0,112,63,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,63,0,114,63,11,11,11,11,11,11,11,11,11,11,11,11,11,255,
		255,255,11,11,11,255,255,255,11,11,11,11,11,11,11,11,11,11,11,11,11,63,0,110,62,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,255,255,255,10,255,255,255,11,11,11,11,11,11,11,11,11,11,11,11,11,11,56,0,106,63,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,255,255,255,255,255,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,55,0,108,59,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,255,255,255,10,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,55,0,110,59,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,254,254,
		254,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,46,0,104,63,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,10,252,252,252,252,252,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,51,0,99,57,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,250,250,250,10,250,250,250,11,11,11,11,11,11,11,11,11,11,11,11,11,11,48,
		0,79,55,11,11,11,11,11,11,11,11,11,11,11,11,11,248,248,248,10,10,10,248,248,248,11,11,11,11,11,11,11,
		11,11,11,11,11,11,55,0,0,65,11,11,11,11,11,11,11,11,11,11,11,11,11,11,10,10,11,11,11,10,10,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,65,0,0,66,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,66,0,0,76,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,76,0,0,78,11,
		11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,78,0,0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,0};

	unsigned char alpha[]={
		0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,34,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
		30,30,30,30,30,30,30,30,30,30,30,30,18,94,221,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,30,150,228,202,202,202,202,202,202,202,202,202,202,
		202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,233,29,169,228,197,197,197,
		197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,
		231,27,158,225,190,190,190,190,190,190,190,190,190,190,190,191,192,194,194,194,192,191,192,194,194,194,192,191,190,190,190,190,
		190,190,190,190,190,190,190,225,26,145,216,181,181,181,181,181,181,181,181,181,181,181,182,186,191,195,194,190,188,190,194,195,
		191,186,182,181,181,181,181,181,181,181,181,181,181,181,216,24,143,210,170,170,170,170,170,170,170,170,170,170,170,172,179,255,
		255,255,194,191,194,255,255,255,179,172,170,170,170,170,170,170,170,170,170,170,170,210,22,129,202,157,157,157,157,157,157,157,
		157,157,157,157,159,165,178,255,255,255,200,255,255,255,178,165,159,157,157,157,157,157,157,157,157,157,157,157,190,21,113,188,
		143,143,143,143,143,143,143,143,143,143,143,144,148,158,175,255,255,255,255,255,175,158,148,144,143,143,143,143,143,143,143,143,
		143,143,143,172,19,110,169,128,128,128,128,128,128,128,128,128,128,128,128,129,135,151,175,255,255,255,175,151,135,129,128,128,
		128,128,128,128,128,128,128,128,128,128,160,17,108,149,113,113,113,113,113,113,113,113,113,113,113,113,114,121,139,165,255,255,
		255,165,139,121,114,113,113,113,113,113,113,113,113,113,113,113,113,123,15,90,137,98,98,98,98,98,98,98,98,98,98,98,
		99,105,120,143,255,255,255,255,255,143,120,105,99,98,98,98,98,98,98,98,98,98,98,98,109,14,66,108,82,82,82,82,
		82,82,82,82,82,82,82,85,96,119,255,255,255,157,255,255,255,119,96,85,82,82,82,82,82,82,82,82,82,82,82,91,
		11,44,77,67,67,67,67,67,67,67,67,67,67,67,72,86,255,255,255,121,114,121,255,255,255,86,72,67,67,67,67,67,
		67,67,67,67,67,67,77,10,16,64,53,53,53,53,53,53,53,53,53,53,53,56,66,81,90,89,78,71,78,89,90,81,
		66,56,53,53,53,53,53,53,53,53,53,53,53,64,8,12,48,39,39,39,39,39,39,39,39,39,39,39,41,45,51,53,
		51,45,42,45,51,53,51,45,41,39,39,39,39,39,39,39,39,39,39,39,48,6,10,34,26,26,26,26,26,26,26,26,
		26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,34,5,7,22,16,
		16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
		16,16,22,3,3,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
		7,7,7,7,7,7,7,7,7,7,2};

	int value;
	if(Graph_Valid(pic))
	{
		Graph_Free(pic);
	}
	Graph_Init(pic);
	pic->have_alpha = IS_TRUE;
	pic->type = TYPE_PNG;
	pic->alpha = 255;
	value = Graph_Create(pic, 39, 20); 
	if(value == 0)
	{
		memcpy(pic->rgba[0], red, sizeof(red));
		memcpy(pic->rgba[1], green, sizeof(green));
		memcpy(pic->rgba[2], blue, sizeof(blue));
		memcpy(pic->rgba[3], alpha, sizeof(alpha));
	}
	return value;
}

LCUI_EXPORT(int) Load_Graph_Default_TitleBar_CloseBox_Down(LCUI_Graph *pic)
/* 功能：载入图形，该图形为标题栏上的关闭按钮，按钮为按下状态 */
{
	unsigned char red[]={
		255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,31,198,216,216,216,216,216,216,216,216,216,216,216,216,216,216,216,216,216,
		216,216,216,216,216,216,216,216,216,216,216,216,216,216,216,216,216,216,202,0,43,210,177,177,177,177,177,177,177,177,177,177,
		177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,213,0,44,209,179,179,179,
		179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,
		212,0,43,209,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,181,
		181,181,181,181,181,181,181,211,0,42,208,184,184,184,184,184,184,184,184,184,184,184,184,184,184,183,183,183,184,184,184,183,
		183,183,184,184,184,184,184,184,184,184,184,184,184,184,211,0,43,209,189,189,189,189,189,189,189,189,189,189,189,189,189,188,
		186,185,185,186,187,186,185,185,186,188,189,189,189,189,189,189,189,189,189,189,189,211,0,40,209,193,193,193,193,193,193,193,
		193,193,193,193,193,192,190,255,255,255,185,186,185,255,255,255,190,192,193,193,193,193,193,193,193,193,193,193,212,0,41,211,
		199,199,199,199,199,199,199,199,199,199,199,199,198,196,191,255,255,255,185,255,255,255,191,196,198,199,199,199,199,199,199,199,
		199,199,199,214,0,42,213,204,204,204,204,204,204,204,204,204,204,204,204,204,201,197,191,255,255,255,255,255,191,197,201,204,
		204,204,204,204,204,204,204,204,204,204,216,0,40,216,210,210,210,210,210,210,210,210,210,210,210,210,210,209,206,198,190,255,
		255,255,190,198,206,209,210,210,210,210,210,210,210,210,210,210,210,220,0,38,220,216,216,216,216,216,216,216,216,216,216,216,
		216,216,215,211,201,191,254,254,254,191,201,211,215,216,216,216,216,216,216,216,216,216,216,216,223,0,36,225,222,222,222,222,
		222,222,222,222,222,222,222,222,221,216,206,195,251,251,251,251,251,195,206,216,221,222,222,222,222,222,222,222,222,222,222,228,
		0,29,233,228,228,228,228,228,228,228,228,228,228,228,228,225,214,201,248,248,248,188,248,248,248,201,214,225,228,228,228,228,
		228,228,228,228,228,228,236,0,0,239,234,234,234,234,234,234,234,234,234,234,234,234,227,213,245,245,245,194,197,194,245,245,
		245,213,227,234,234,234,234,234,234,234,234,234,234,242,0,0,243,240,240,240,240,240,240,240,240,240,240,240,240,234,220,207,
		201,201,208,214,208,201,201,207,220,234,240,240,240,240,240,240,240,240,240,240,246,0,0,247,244,244,244,244,244,244,244,244,
		244,244,244,244,239,229,219,216,219,229,235,229,219,216,219,229,239,244,244,244,244,244,244,244,244,244,244,247,0,0,251,249,
		249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,249,
		249,249,251,0,0,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,
		252,252,252,252,252,252,252,252,252,252,0};

	unsigned char green[]={
		255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,68,72,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,
		74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,72,0,94,74,37,37,37,37,37,37,37,37,37,37,
		37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,82,0,96,72,37,37,37,
		37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,
		80,0,94,73,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,
		37,37,37,37,37,37,37,81,0,92,72,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,
		37,37,37,37,37,37,37,37,37,37,37,37,37,37,81,0,93,72,37,37,37,37,37,37,37,37,37,37,37,37,37,37,
		37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,81,0,88,70,37,37,37,37,37,37,37,
		37,37,37,37,37,37,37,255,255,255,37,37,37,255,255,255,37,37,37,37,37,37,37,37,37,37,37,37,81,0,89,71,
		38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,255,255,255,38,255,255,255,38,38,38,38,38,38,38,38,38,38,
		38,38,38,85,0,91,71,42,42,42,42,42,42,42,42,42,42,42,42,42,42,41,40,255,255,255,255,255,40,41,42,42,
		42,42,42,42,42,42,42,42,42,42,85,0,88,76,47,47,47,47,47,47,47,47,47,47,47,47,47,47,46,44,42,255,
		255,255,42,44,46,47,47,47,47,47,47,47,47,47,47,47,47,92,0,83,81,52,52,52,52,52,52,52,52,52,52,52,
		52,52,52,50,47,44,254,254,254,44,47,50,52,52,52,52,52,52,52,52,52,52,52,52,98,0,79,85,57,57,57,57,
		57,57,57,57,57,57,57,57,57,54,51,46,252,252,252,252,252,46,51,54,57,57,57,57,57,57,57,57,57,57,57,103,
		0,63,97,62,62,62,62,62,62,62,62,62,62,62,62,61,56,50,249,249,249,44,249,249,249,50,56,61,62,62,62,62,
		62,62,62,62,62,62,122,0,0,108,67,67,67,67,67,67,67,67,67,67,67,67,64,57,247,247,247,48,49,48,247,247,
		247,57,64,67,67,67,67,67,67,67,67,67,67,136,0,0,114,72,72,72,72,72,72,72,72,72,72,72,72,69,62,55,
		52,52,56,59,56,52,52,55,62,69,72,72,72,72,72,72,72,72,72,72,142,0,0,124,76,76,76,76,76,76,76,76,
		76,76,76,76,73,68,62,61,62,68,71,68,62,61,62,68,73,76,76,76,76,76,76,76,76,76,76,124,0,0,128,80,
		80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,
		80,80,128,0,0,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,
		83,83,83,83,83,83,83,83,83,83,0};

	unsigned char blue[]={
		255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,85,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,0,118,42,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,51,0,120,42,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		51,0,117,42,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,52,0,115,40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,
		1,1,0,0,0,0,0,0,0,0,0,0,0,0,51,0,117,39,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		2,3,2,2,1,2,2,3,2,1,0,0,0,0,0,0,0,0,0,0,0,50,0,110,38,0,0,0,0,0,0,0,
		0,0,0,0,0,0,2,255,255,255,4,4,4,255,255,255,2,0,0,0,0,0,0,0,0,0,0,0,51,0,111,38,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,255,255,255,6,255,255,255,3,1,0,0,0,0,0,0,0,0,
		0,0,0,54,0,114,38,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,5,255,255,255,255,255,5,3,2,1,
		1,1,1,1,1,1,1,1,1,1,53,0,110,43,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,8,255,
		255,255,8,7,6,6,6,6,6,6,6,6,6,6,6,6,6,62,0,104,48,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,10,254,254,254,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,68,0,99,51,16,16,16,16,
		16,16,16,16,16,16,16,16,16,15,14,13,252,252,252,252,252,13,14,15,16,16,16,16,16,16,16,16,16,16,16,73,
		0,79,64,22,22,22,22,22,22,22,22,22,22,22,22,21,19,16,250,250,250,13,250,250,250,16,19,21,22,22,22,22,
		22,22,22,22,22,22,94,0,0,77,27,27,27,27,27,27,27,27,27,27,27,27,25,21,248,248,248,16,17,16,248,248,
		248,21,25,27,27,27,27,27,27,27,27,27,27,110,0,0,83,32,32,32,32,32,32,32,32,32,32,32,32,30,25,21,
		19,19,21,23,21,19,19,21,25,30,32,32,32,32,32,32,32,32,32,32,117,0,0,94,36,36,36,36,36,36,36,36,
		36,36,36,36,34,30,27,26,27,30,33,30,27,26,27,30,34,36,36,36,36,36,36,36,36,36,36,94,0,0,99,40,
		40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,
		40,40,99,0,0,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,
		43,43,43,43,43,43,43,43,43,43,0};

	unsigned char alpha[]={
		0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,34,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,
		30,30,30,30,30,30,30,30,30,30,30,30,18,111,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,30,179,241,202,202,202,202,202,202,202,202,202,202,
		202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,202,243,29,177,238,197,197,197,
		197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,
		240,27,168,233,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,190,
		190,190,190,190,190,190,190,236,26,157,227,181,181,181,181,181,181,181,181,181,181,181,181,182,183,185,186,185,183,182,183,185,
		186,185,183,182,181,181,181,181,181,181,181,181,181,181,230,24,155,219,170,170,170,170,170,170,170,170,170,170,170,170,171,175,
		182,186,185,180,178,180,185,186,182,175,171,170,170,170,170,170,170,170,170,170,170,222,22,129,202,157,157,157,157,157,157,157,
		157,157,157,157,157,160,167,255,255,255,185,182,185,255,255,255,167,160,157,157,157,157,157,157,157,157,157,157,207,21,128,188,
		143,143,143,143,143,143,143,143,143,143,143,143,145,152,167,255,255,255,192,255,255,255,167,152,145,143,143,143,143,143,143,143,
		143,143,143,194,19,125,169,128,128,128,128,128,128,128,128,128,128,128,128,129,134,145,164,255,255,255,255,255,164,145,134,129,
		128,128,128,128,128,128,128,128,128,128,175,17,108,149,113,113,113,113,113,113,113,113,113,113,113,113,113,114,121,139,165,255,
		255,255,165,139,121,114,113,113,113,113,113,113,113,113,113,113,113,156,15,90,137,98,98,98,98,98,98,98,98,98,98,98,
		98,98,99,107,127,156,255,255,255,156,127,107,99,98,98,98,98,98,98,98,98,98,98,98,145,14,66,108,82,82,82,82,
		82,82,82,82,82,82,82,82,83,90,106,132,255,255,255,255,255,132,106,90,83,82,82,82,82,82,82,82,82,82,82,117,
		11,44,77,67,67,67,67,67,67,67,67,67,67,67,67,70,82,107,255,255,255,149,255,255,255,107,82,70,67,67,67,67,
		67,67,67,67,67,67,87,10,16,64,53,53,53,53,53,53,53,53,53,53,53,53,59,74,255,255,255,111,104,111,255,255,
		255,74,59,53,53,53,53,53,53,53,53,53,53,74,8,12,48,39,39,39,39,39,39,39,39,39,39,39,39,42,53,69,
		79,77,65,58,65,77,79,69,53,42,39,39,39,39,39,39,39,39,39,39,58,6,10,34,26,26,26,26,26,26,26,26,
		26,26,26,26,28,32,39,40,39,32,30,32,39,40,39,32,28,26,26,26,26,26,26,26,26,26,26,34,5,7,22,16,
		16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
		16,16,22,3,3,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
		7,7,7,7,7,7,7,7,7,7,2};

	int value;
	if(Graph_Valid(pic))
	{
		Graph_Free(pic);
	}
	Graph_Init(pic);
	pic->have_alpha = IS_TRUE;
	pic->alpha = 255;
	pic->type = TYPE_PNG;
	value = Graph_Create(pic, 39, 20); 
	if(value == 0)
	{
		memcpy(pic->rgba[0], red, sizeof(red));
		memcpy(pic->rgba[1], green, sizeof(green));
		memcpy(pic->rgba[2], blue, sizeof(blue));
		memcpy(pic->rgba[3], alpha, sizeof(alpha));
	}
	return value;
}

LCUI_EXPORT(int) Load_Graph_Default_TitleBar_BG(LCUI_Graph *pic)
/* 功能：载入默认的标题栏背景图 */
{
	unsigned char red[]={153,81,77,69,62,56,54,54,54,54,54,54,54,54,53,53,53,53,53,53,52,52,46,148,13};
	unsigned char green[]={248,209,208,205,201,196,192,193,193,193,193,193,193,193,192,191,191,191,190,190,189,189,185,243,182};
	unsigned char blue[]={255,249,248,245,243,240,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,237,254,226};
	int value;
	if(Graph_Valid(pic))
	{
		Graph_Free(pic);
	}
	Graph_Init(pic);
	pic->have_alpha = IS_TRUE;
	pic->alpha = 255;
	pic->type = TYPE_PNG;
	value = Graph_Create(pic, 1, 25); 
	if(value == 0)
	{
		memcpy(pic->rgba[0], red, sizeof(red));
		memcpy(pic->rgba[1], green, sizeof(green));
		memcpy(pic->rgba[2], blue, sizeof(blue));
		memset(pic->rgba[3], 255, sizeof(red));
	}
	return value;
}
