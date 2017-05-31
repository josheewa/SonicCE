//--------------------------------------
// Program Name: Sonic CE
// Author:       Tyulis (alias Grégori Mignerot)
// License:      GPLv3
// Description:  Sonic for TI CE
//--------------------------------------

#include "stdheader.h"
//Specific headers
#include "loader.h"
#include "game.h"
#include <debug.h>
#include "gfx/sprite_gfx.h"

// stdarg.h, setjmp.h, assert.h, ctype.h, float.h, iso646.h, limits.h, errno.h, debug.h, intce.h

/* Put your function prototypes here */
void titlescreen(void);

/* Put all your globals here. */

void main(void)
{
	malloc(0);
	gfx_Begin(gfx_8bpp);
	gfx_SetPalette(sprite_gfx_pal, sizeof(sprite_gfx_pal), 0);
	gfx_SetTransparentColor(6);
	dbg_sprintf(dbgout,"Init ok");
	load_sprites();
	dbg_sprintf(dbgout,"Sprites ok");
	titlescreen();
	load_save();
	dbg_sprintf(dbgout,"Save ok");
	game();
	dbg_sprintf(dbgout,"Game ok");
	if(save_progress())
		os_PutStrLine("Error when saving");
	dbg_sprintf(dbgout,"Save ok ok");
	//unload_sprites();
	dbg_sprintf(dbgout,"Unload ok");
	gfx_End();
}

/* Put other functions here */
void titlescreen(void)
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
	gfx_BlitBuffer();
	while(!os_GetCSC());
}

