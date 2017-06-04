#include "physic.h"

uint24_t tile_collisions[TILE_NUMBER]=[
	NONE,				//air block
	NONE,				//standard wall 1
	UP,					//grass 1
	UP,					//grassy 2
	UP|DGL_UP_LEFT,		//loop top left
	UP|IN_UP,			//loop top middle
	UP|DGL_UP_RIGHT,	//loop top right
	NONE,				//standard wall 2
	NONE,				//waterfall
	DGL_DOWN_LEFT,		//descending grass
	DGL_DOWN_RIGHT,		//ascending grass
	MID_LEFT,			//loop middle left
	NONE,				//loop center
	MID_RIGHT			//loop middle right
	//To continue (2 first lines of tileset ok)
]

void update_sprite(void){
	uint8_t tile=actlevel.data[((sonic.box.y+sonic.box.h)/32)*TILEMAP_WIDTH+((sonic.box.x+sonic.box.w)/32)];
	sonic.state&=0x1F; //0b00011111, to remove loop and dgl flags
	sonic.spr_rotation=NOROTATION;
	switch(tile){
		case 4: sonic.state|=LOOP_ANGLE; sonic.spr_rotation=ROTATE270; break;
		case 5: sonic.state|=LOOP; sonic.spr_rotation=ROTATE180; break;
		case 6: sonic.state|=LOOP_ANGLE; sonic.spr_rotation=ROTATE180; break;
		case 9: sonic.state|=DGL; break;
		case 10: sonic.state|=DGL; sonic.spr_rotation=ROTATION90; break;
		case 11: sonic.state|=LOOP; sonic.spr_rotation=ROTATE270; break;
		case 13: sonic.state|=LOOP; sonic.spr_rotation=ROTATE90; break;
		case 18: sonic.state|=LOOP_ANGLE; break;
		case 20: sonic.state|=LOOP; break;
		case 22: sonic.state|=DGL; break;
		case 24: sonic.state|=DGL; sonic.spr_rotation=ROTATION90; break;
		case 29: sonic.state|=DGL; sonic.spr_rotation=ROTATION90; break;
		case 46: sonic.state|=DGL; break;
		default: break;
	}
	if(sonic.state&WALK && !sonic.state&DGL && !sonic.state&LOOP_ANGLE){
		if(sonic.frame==1){
			sonic.tmpsprite=sonic_walk_1;
			sonic.frame++;
		}else if(sonic.frame==2){
			sonic.tmpsprite=sonic_walk_2;
			sonic.frame++;
		}else{
			sonic.tmpsprite=sonic_walk_3;
			sonic.frame=1;
		}
	}else if((sonic.state&WALK && sonic.state&DGL) || (sonic.state&WALK && sonic.state&LOOP_ANGLE)){
		if(sonic.frame==1){
			sonic.tmpsprite=sonic_walk_wall_1;
			sonic.frame++;
		}else if(sonic.frame==2){
			sonic.tmpsprite=sonic_walk_wall_2;
			sonic.frame++;
		}else{
			sonic.tmpsprite=sonic_walk_wall_3;
			sonic.frame=1;
		}
	}else if(sonic.state&RUN && !sonic.state&DGL && !sonic.state&LOOP_ANGLE){
		if(sonic.frame==1){
			sonic.tmpsprite=sonic_run_1;
			sonic.frame++;
		}else{
			sonic.tmpsprite=sonic_run_2;
			sonic.frame=1;
		}
	}else if((sonic.state&RUN && sonic.state&DGL) || (sonic.state&WALK && sonic.state&LOOP_ANGLE)){
		if(sonic.frame==1){
			sonic.tmpsprite=sonic_run_wall_1;
			sonic.frame++;
		}else{
			sonic.tmpsprite=sonic_run_wall_2;
			sonic.frame=1;
		}
	}else if(sonic.state&JUMP){
		sonic.tmpsprite=sonic_ball;
	}else if(sonic.state&STANDBY){
		sonic.tmpsprite=sonic_standby;
	}
	if(sonic.spr_rotation==ROTATION90){
		gfx_RotateSpriteC(sonic.tmpsprite,sonic.actsprite);
	}else if(sonic.spr_rotation==ROTATION180){
		gfx_RotateSpriteC(sonic.tmpsprite,sonic.actsprite);
		gfx_RotateSpriteC(sonic.actsprite,sonic.actsprite);
	}else if(sonic.spr_rotation==ROTATION270){
		gfx_RotateSpriteCC(sonic.tmpsprite,sonic.actsprite);
	}else{
		*sonic.actsprite=*sonic.tmpsprite;
	}		
}

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
	if(sonic.jumping){
		sonic.state=JUMP;
	}else if(sonic.speed<-40 || sonic.speed>40){
		sonic.state=RUN;
	}else if(sonic.speed==0){
		sonic.state=STANDBY;
	}else{
		sonic.state=WALK;
	update_sprite();
	//for top left
	collmask=tile_collisions[actlevel.data[(sonic.box.y/32)*TILEMAP_WIDTH+(sonic.box.x/32)]];
	if(collmask&DOWN && sonic.box.y>sonic.box.y-sonic.box.y%32){
		sonic.box.y+=32-(sonic.box.y%32);
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}else if(collmask&MID_UP && sonic.box.y>sonic.box.y-sonic.box.y%32+16){
		sonic.box.y+=32-(sonic.box.y%32)-16;
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}else if(collmask&IN_UP && sonic.box.y>sonic.box.y-sonic.box.y%32+30){
		sonic.box.y+=32-(sonic.box.y%32)-30;
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}
	if(collmask&RIGHT && sonic.box.x>sonic.box.x-sonic.box.x%32){
		sonic.box.x+=32-(sonic.box.x%32);
		sonic.speed/=5;
		sonic.state=PUSH;
	}else if(collmask&MID_LEFT && sonic.box.x>sonic.box.x-sonic.box.x%32+16){
		sonic.box.x+=32-(sonic.box.x%32)-16;
		sonic.speed/=5;
		sonic.state=PUSH;
	}else if(collmask&IN_LEFT && sonic.box.x>sonic.box.x-sonic.box.x%32+30){
		sonic.box.x+=32-(sonic.box.x%32)-30;
		sonic.speed/=5;
		sonic.state=PUSH;
	}
	//for down right
	collmask=tile_collisions[actlevel.data[((sonic.box.y+sonic.box.h)/32)*TILEMAP_WIDTH+((sonic.box.x+sonic.box.w)/32)]];
	if(collmask&UP && (sonic.box.y+sonic.box.h)<(sonic.box.y+sonic.box.h)+(sonic.box.y+sonic.box.h)%32){
		sonic.box.y-=(sonic.box.y+sonic.box.h)%32;
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}else if(collmask&MID_DOWN && (sonic.box.y+sonic.box.h)<(sonic.box.y+sonic.box.h)+(sonic.box.y+sonic.box.h)%32-16){
		sonic.box.y-=(sonic.box.y+sonic.box.h)%32+16;
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}else if(collmask&IN_DOWN && (sonic.box.y+sonic.box.h)<(sonic.box.y+sonic.box.h)+(sonic.box.y+sonic.box.h)%32-30){
		sonic.box.y-=(sonic.box.y+sonic.box.h)%32+30;
		sonic.jumping=false;
		sonic.gravity=BASE_GRAVITY;
	}
	if(collmask&LEFT && (sonic.box.x+sonic.box.w)<(sonic.box.x+sonic.box.w)+(sonic.box.x+sonic.box.w)%32){
		sonic.box.x-=(sonic.box.x+sonic.box.w)%32;
		sonic.speed/=5;
		sonic.state=PUSH;
	}else if(collmask&MID_RIGHT && (sonic.box.x+sonic.box.w)<(sonic.box.x+sonic.box.w)+(sonic.box.x+sonic.box.w)%32-16){
		sonic.box.x+=(sonic.box.x+sonic.box.w)%32+16;
		sonic.speed/=5;
		sonic.state=PUSH;
	}else if(collmask&IN_RIGHT && (sonic.box.x+sonic.box.w)<(sonic.box.x+sonic.box.w)+(sonic.box.x+sonic.box.w)%32-30){
		sonic.box.x+=(sonic.box.x+sonic.box.w)%32+30;
		sonic.speed/=5;
		sonic.state=PUSH;
	}
	if(collmask&DGL_DOWN_RIGHT && (sonic.box.y+sonic.box.h)%32>(sonic.box.x+sonic.box.w)%32){
		sonic.box.y+=(sonic.box.y+sonic.box.h)%32-(sonic.box.x+sonic.box.w)%32;
		sonic.gravity=BASE_GRAVITY;
		sonic.jumping=false;
		if(control&LEFT){
			sonic.speed+=1;
		}else if(control&RIGHT){
			sonic.speed-=1;
		}
	}else if(collmask&DGL_DOWN_LEFT && (sonic.box.y+sonic.box.h)%32>sonic.box.x%32){
		sonic.box.y+=(sonic.box.y+sonic.box.h)%32-(sonic.box.x%32);
		sonic.gravity=BASE_GRAVITY;
		sonic.jumping=false;
		if(control&LEFT){
			sonic.speed-=1;
		}else if(control&RIGHT){
			sonic.speed+=1;
		}
	}
	if(collmask&HALF_DOWN_LEFT && (sonic.box.y+sonic.box.h)%32>16 && (sonic.box.x+sonic.box.w)%32>2){
		sonic.box.x-=(sonic.box.x+sonic.box.w)%32;
		sonic.speed/=4;
	}
	if(collmask&HALF_DOWN_RIGHT && (sonic.box.y+sonic.box.h)%32>16 && sonic.box.x%32<30){
		sonic.box.x+=sonic.box.x%32;
		sonic.speed/=4;
	}
	if(!collmask&UP && !collmask&MID_UP && !collmask&DGL_DOWN_LEFT && !collmask&DGL_DOWN_LEFT)
		sonic.gravity+=1;
	
}
