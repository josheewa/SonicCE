#include "game.h"
#include "keydetect.h"

//The main game module
sonic_t sonic;
level_t* actlevel;
uint24_t j;
int act_x;
int act_y;
uint8_t debugcombo;
bool debug;

void init_sonic(void)
{
	sonic.box.x=actlevel->depart_tile_x;
	sonic.box.y=actlevel->depart_tile_y;
	sonic.box.w=20;
	sonic.box.h=23;
	sonic.speed=0;
	sonic.actsprite=sonic_standby;
	sonic.spr_mirror=NO_MIRROR;
	sonic.spr_rotation=NO_ROTATION;
}

uint8_t game(void)
{
	debug=false;
	debugcombo=0;
	load_game_data();
	actlevel=load_level();
	if(actlevel==NULL)
		return 1;
	load_tilemap();
	init_sonic();
	intro_screen();
	//debug : up, down, left, right, alpha
	while(1){
		if(keyCheck(dir_group,up)&&debugcombo==0)
			debugcombo++;
		if(keyCheck(dir_group,down)&&debugcombo==1)
			debugcombo++;
		if(keyCheck(dir_group,left)&&debugcombo==2)
			debugcombo++;
		if(keyCheck(dir_group,right)&&debugcombo==3)
			debugcombo++;
		if(keyCheck(alpha_group,alpha)&&debugcombo==4)
			debug=true;
		if(keyCheck(annul_group,enter))
			break;
	}
			
	act_x=actlevel->depart_tile_x*32-160;
	act_y=actlevel->depart_tile_y*32-120;
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
		if(act_x<0){act_x=0;}
		if(act_x>TILEMAP_WIDTH*32-320){act_x=TILEMAP_WIDTH*32-10*32;}
		if(act_y<0){act_y=0;}
		if(act_y>TILEMAP_HEIGHT*32-255){act_y=TILEMAP_HEIGHT*32-8*32;}
		gfx_Tilemap(&tilemap,act_x,act_y);
		if(debug){
			gfx_SetTextScale(1,1);
			gfx_SetTextXY(0,0);
			gfx_PrintInt(act_x,4);
			gfx_SetTextXY(0,30);
			gfx_PrintInt(act_y,4);
		}
		gfx_SwapDraw();
	}
	free(&tilemap);
	free(actlevel);
	ti_CloseAll();
	free(tileset_tiles);
	free(item_desc);
	return 0;
}

void intro_screen(void)
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
