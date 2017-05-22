#ifndef _SONICCE_PHYSIC_H_
#define _SONICCE_PHYSIC_H_
#include "common.h"
#include "game.h"

bool verifCollision(box_t element, box_t obstacle);
uint8_t deterRelativePosition(box_t element, box_t obstacle);
point_t deterCenter(box_t box);
void jumpModifier(void);
void applyCollisions(box_t previous, box_t newbox);
#endif
