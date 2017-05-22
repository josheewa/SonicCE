/*Sonic CE--A Sonic clone for TI83Premium CE
*    Copyright (C) 2017  Grégori Mignerot
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//--------------------------------------
// Program Name: Sonic CE
// Author:       Tyulis (alias Grégori Mignerot)
// License:      GPLv3
// Description:  Sonic for TI CE
//--------------------------------------

#include "common.h"
//Specific headers
#include "loader.h"
#include "game.h"
#include "gfx/sprite_gfx.h"

// stdarg.h, setjmp.h, assert.h, ctype.h, float.h, iso646.h, limits.h, errno.h, debug.h, intce.h

/* Put your function prototypes here */
void titleScreen(void);

/* Put all your globals here. */

void main(void)
{
	malloc(0); //only to compile it into the program
	gfx_Begin(gfx_8bpp);
	gfx_SetPalette(sprite_gfx_pal, sizeof(sprite_gfx_pal), 0);
	gfx_SetTransparentColor(6);
	loadSprites();
	titleScreen();
	loadSave();
	game();
	while(!os_GetCSC());
	saveProgress();
	gfx_End();
	prgm_CleanUp();
}

/* Put other functions here */
void titleScreen(void)
{
	//draws the controls presentation
	gfx_SetDrawBuffer();
	gfx_FillScreen(3);
	gfx_SetTextBGColor(6);	
	gfx_SetTextTransparentColor(6);	
	gfx_SetTextFGColor(255);
	gfx_SetTextScale(3,3);
	gfx_PrintStringXY("Sonic TI Edition", 0, 10);
	gfx_SetTextScale(2,2);
	gfx_PrintStringXY("Fleches: se deplacer", 20, 60);
	gfx_PrintStringXY("2nde   : sauter", 20, 90);
	gfx_PrintStringXY("Alpha  : pause", 20, 120);
	gfx_PrintStringXY("Annul. : fermer le jeu", 20, 150);
	gfx_SetTextScale(1,2);
	gfx_PrintStringXY("<Appuyez sur une touche pour commencer...>", 15, 200);
	gfx_SwapDraw();
	while(!os_GetCSC());
}
