#ifndef _SONICCE_PHYSIC_H_
#define _SONICCE_PHYSIC_H_
#include "common.h"

bool verif_collision(box_t element, box_t obstacle);
uint8_t deter_relative_position(box_t element, box_t obstacle);
point_t deter_center(box_t box);
#endif
