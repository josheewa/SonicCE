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

bool verif_collision(box_t element, box_t obstacle)
{
    uint8_t relatpos=deter_relative_position(element, obstacle);
    if(relatpos&REL_IN_MASK){
        return true;
    }else{
    	return false;
    }
}

uint8_t deter_relative_position(box_t element, box_t obstacle)
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

point_t deter_center(box_t rect)
{
    point_t center;
    center.x=(rect.x+rect.w)/2;
    center.y=(rect.y+rect.h)/2;
    return center;
}

void apply_physic(void)
{
	uint8_t tile_in=actlevel.data[sonic.act_tile];
	uint24_t act_tile_collisions=tile_collisions[tile_in];
}
