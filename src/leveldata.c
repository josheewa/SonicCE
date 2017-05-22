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
#include "common.h"

uint8_t tiles_collisions[TILE_NUMBER]={NONE, //air tile
										TOP|DOWN|LEFT|RIGHT,    //standard ground,
										OBLIQUE_TR|LEFT|DOWN,   //oblique ground
										OBLIQUE_TL|RIGHT|DOWN,  //oblique ground
										LEFT,                   //loop left
										NONE,                   //loop center
										RIGHT,                  //loop right
										TOP|DOWN|LEFT|RIGHT,    //loop entry
										TOP|DOWN|LEFT|RIGHT,    //middle loop entry
										TOP|DOWN|LEFT|RIGHT,    //loop end
										//to continue
};