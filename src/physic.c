#include "physic.h"

uint24_t tile_collisions[TILE_NUMBER]=[
	NONE,				//air block
	NONE,				//standard wall 1
	UP|LEFT|RIGHT,		//grassy tile 1
	UP|LEFT|RIGHT,		//grassy tile 2
	UP|DGL_UP_LEFT,		//loop top left
	UP|IN_UP,			//loop top middle
	UP|DGL_UP_RIGHT,	//loop top right
	NONE,				//standard wall 2
	NONE,				//waterfall
	DGL_DOWN_LEFT,		//descending grass
	DGL_DOWN_RIGHT,		//ascending grass
	MID_LEFT,			//loop middle left
	NONE,				//loop center
	MID_RIGHT,			//loop middle right
	//To continue (2 first lines of tileset ok)
]

void apply_physic(uint8_t control)
{
	uint24_t collmask=NONE;
	if(control&LEFT){
		sonic.speed-=1;
	}else if(control&RIGHT){
		sonic.speed+=1;
	}else if(control==NONE && sonic.speed>0){
		sonic.speed-=1;
	}else if(control==NONE && sonic.speed<0){
		sonic.speed+=1;
	}
	sonic.box.x+=sonic.speed;
	sonic.box.y-=sonic.gravity;
	if(sonic.jumping)
		sonic.y+=JUMP_CONSTANT;
	//for top left
	collmask=tile_collisions[actlevel.data[(sonic.box.y/32)*TILEMAP_WIDTH+(sonic.box.x/32)]];
	if(collmask&DOWN && sonic.box.y>sonic.box.y-sonic.box.y%32+26){
		sonic.box.y+=32-(sonic.box.y%32);
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}else if(collmask&MID_UP && sonic.box.y>sonic.box.y-sonic.box.y%32+10){
		sonic.box.y+=16-(sonic.box.y%16);
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}
	if(collmask&RIGHT && sonic.box.x>sonic.box.x-sonic.box.x%32+26){
		sonic.box.x+=32-(sonic.box.x%32);
		sonic.speed/=5;
	}else if(collmask&MID_LEFT && sonic.box.x>sonic.box.x-sonic.box.x%32+10){
		sonic.box.x+=16-(sonic.box.x%16);
		sonic.speed/=5;
	}
	//for down right
	collmask=tile_collisions[actlevel.data[((sonic.box.y+sonic.box.h)/32)*TILEMAP_WIDTH+((sonic.box.x+sonic.box.w)/32)]];
	if(collmask&UP && (sonic.box.y+sonic.box.h)<(sonic.box.y+sonic.box.h)+(sonic.box.y+sonic.box.h)%32-26){
		sonic.box.y-=(sonic.box.y+sonic.box.h)%32;
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}else if(collmask&MID_UP && (sonic.box.y+sonic.box.h)<(sonic.box.y+sonic.box.h)+(sonic.box.y+sonic.box.h)%32-10){
		sonic.box.y-=(sonic.box.y+sonic.box.h)%16;
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}
	if(!collmask&UP && !collmask&MID_UP)
		sonic.gravity+=1;
	if(collmask&RIGHT && (sonic.box.x+sonic.box.w)<(sonic.box.x+sonic.box.w)+(sonic.box.x+sonic.box.w)%32-26){
		sonic.box.x-=(sonic.box.x+sonic.box.w)%32;
		sonic.speed/=5;
	}else if(collmask&MID_LEFT && (sonic.box.x+sonic.box.w)<(sonic.box.x+sonic.box.w)+(sonic.box.x+sonic.box.w)%32-10){
		sonic.box.x+=(sonic.box.x+sonic.box.w)%16;
		sonic.speed/=5;
	}
	if(collmask&DGL_DOWN_RIGHT && (sonic.box.y+sonic.box.h)%32>(sonic.box.x+sonic.box.w)%32){
		sonic.box.y+=(sonic.box.y+sonic.box.h)%32-(sonic.box.x+sonic.box.w)%32;
		sonic.gravity=BASE_GRAVITY;
		sonic.jumping=false;
	}else if(collmask&DGL_DOWN_LEFT && (sonic.box.y+sonic.box.h)%32>32-(sonic.box.x+sonic.box.w)%32){
		sonic.box.y+=(sonic.box.y+sonic.box.h)%32-(32-(sonic.box.x+sonic.box.w)%32);
		sonic.gravity=BASE_GRAVITY;
		sonic.jumping=false;
	}
}