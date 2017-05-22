/*Sonic CE--A Sonic clone for TI83Premium CE
*    Copyright (C) 2017  Grégori Mignerot
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
