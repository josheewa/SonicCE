#include "physic.h"

//Y data for sonic jumps. To adapt with speed.
int8_t jumpdata[SONIC_JUMP_STATES_NUMBER]={0,6,11,15,19,22,25,28,30,32,34,35,36,37,37,38,38,39,39,39,39,38,38,37,36,35,33,31,29,26,23,19,15,11,6,0,-6,-13,-20,-28,-37,-47,-58,-70,-83,-97,-112,-127};
//                   0            5              10             15             20              25             30           35               40                  45        47
uint8_t jumpidx;
box_t previousbox;

bool verifCollision(box_t element, box_t obstacle)
{
    uint8_t relatpos=deterRelativePosition(element, obstacle);
    if(relatpos&REL_IN_MASK){
        return true;
    }else{
    	return false;
    }
}

uint8_t deterRelativePosition(box_t element, box_t obstacle)
{
    uint8_t pos=0;
    if(element.x>=(obstacle.x+obstacle.w))
        pos|=RIGHT;
    if((element.x+element.w)<=obstacle.x)
        pos|=LEFT;
    if(element.y>=(obstacle.y+obstacle.h))
        pos|=DOWN;
    if((element.y+element.h)<=obstacle.y)
        pos|=UP;
    if(pos!=0)
    	return pos;
    else{
    	if((element.y+element.h)<(obstacle.y+obstacle.h))
    		pos|=IN_UP;
    	if(element.y>obstacle.y)
    		pos|=IN_DOWN;
    	if((element.x+element.w)<(obstacle.x+obstacle.w))
    		pos|=IN_LEFT;
    	if(element.x>obstacle.x)
    		pos|=IN_RIGHT;
    	return pos;
    }
}

point_t deterCenter(box_t rect)
{
    point_t center;
    center.x=(rect.x+rect.w)/2;
    center.y=(rect.y+rect.h)/2;
    return center;
}

void jumpModifier(void)
{
	if(sonic.speed<0x20){
		sonic.jumpstate+=4;
	}else if(sonic.speed>=0x20 && sonic.speed<0x40){
		sonic.jumpstate+=3;
	}else if(sonic.speed>=0x40 && sonic.speed<0x80){
		sonic.jumpstate+=2;
	}else if(sonic.speed>=0x80 && sonic.speed<0x100){
		sonic.jumpstate+=1;
	}
	previousbox=sonic.box;
	if(sonic.jumpstate>=SONIC_JUMP_STATES_NUMBER){
		sonic.box.y-=16;
	}else{
		sonic.box.y+=jumpdata[sonic.jumpstate];
	}
	sonic.box.x+=sonic.speed/0x20;
	applyCollisions(previousbox,sonic.box);
}

void applyCollisions(box_t previous, box_t newbox)
{
	//Not implemented
}