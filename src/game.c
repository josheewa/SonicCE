#include "game.h"
#include "keydetect.h"

//The main game module
sonic_t sonic;
level_t* actlevel;
uint24_t j;
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
			
	sonic.box.x=actlevel->depart_tile_x*32-160;
	sonic.box.y=actlevel->depart_tile_y*32-120;
	sonic.act_tile=(sonic.box.y/32*TILEMAP_WIDTH)+(sonic.box.x/32);
	gfx_Tilemap(&tilemap,sonic.box.x,sonic.box.y);
	while(1){
		if(keyCheck(action_group,annul))
			break;
		if(keyCheck(dir_group,up))
			sonic.box.y-=5;
		if(keyCheck(dir_group,down))
			sonic.box.y+=5;
		if(keyCheck(dir_group,left))
			sonic.box.x-=5;
		if(keyCheck(dir_group,right))
			sonic.box.x+=5;
		if(sonic.box.x<0){sonic.box.x=0;}
		if(sonic.box.x>TILEMAP_WIDTH*32-320){sonic.box.x=TILEMAP_WIDTH*32-10*32;}
		if(sonic.box.y<0){sonic.box.y=0;}
		if(sonic.box.y>TILEMAP_HEIGHT*32-255){sonic.box.y=TILEMAP_HEIGHT*32-8*32;}
		apply_physic();
		gfx_Tilemap_NoClip(&tilemap,sonic.box.x-120,sonic.box.y-100);
		gfx_Sprite_NoClip(sonic.actsprite,120,100);
		if(debug){
			if(keyCheck(pgrm_group,prgm))
				debug_menu();
			gfx_SetTextScale(1,1);
			gfx_SetTextXY(0,0);
			gfx_PrintInt(sonic.box.x,4);
			gfx_SetTextXY(0,25);
			gfx_PrintInt(sonic.box.y,4);
		}
		gfx_BlitBuffer();
	}
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
	gfx_BlitBuffer();
}
