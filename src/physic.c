#include "physic.h"

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
