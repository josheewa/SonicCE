#include "game.h"

//The main game module
sonic_t sonic;
level_t* actlevel;
uint24_t j;
uint24_t act_x;
uint24_t act_y;

void initSonic(void)
{
	sonic.box.x=actlevel->depart_tile_x;
	sonic.box.y=actlevel->depart_tile_y;
	sonic.box.w=20;
	sonic.box.h=23;
	sonic.speed=0;
	sonic.actsprite=sonic_standby;
	sonic.spr_mirror=NO_MIRROR;
	sonic.spr_rotation=NO_ROTATION;
	sonic.jumpstate=0;
}

uint8_t game(void)
{
	loadGameData();
	actlevel=loadLevel();
	if(actlevel==NULL)
		return 0;
	loadTiles();
	initSonic();
	introScreen();
	while(!os_GetCSC());
	act_x=actlevel->depart_tile_x;
	act_y=actlevel->depart_tile_y-140;
	gfx_Tilemap(&tilemap,act_x,act_y);
	while(1){
		if(keyCheck(annul_group,annul))
			break;
		if(keyCheck(dir_group,up))
			act_y-=5;
		if(keyCheck(dir_group,down))
			act_y+=5;
		if(keyCheck(dir_group,left))
			act_x-=5;
		if(keyCheck(dir_group,right))
			act_x+=5;
		gfx_Tilemap(&tilemap,act_x,act_y-140);
		gfx_SwapDraw();
	}
	return 1;
}

void introScreen(void)
{
	gfx_ZeroScreen();
	gfx_SetTransparentColor(6);
	gfx_SetColor(18);
	gfx_FillTriangle(0,0, 170,0, 0,450);
	gfx_ScaledTransparentSprite_NoClip(introellipsis,100,50,3,3);
	//readable
	gfx_SetTextFGColor(7);
	gfx_SetTextScale(2,3);
	gfx_PrintStringXY(actlevel->name, 115, 67);
	gfx_SetTextScale(2,2);
	gfx_PrintStringXY("Acte ",140,97);
	gfx_SetTextXY(220,97);
	gfx_PrintUInt(actlevel->act_number,1);
	gfx_SwapDraw();
}
