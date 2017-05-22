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
#ifndef _SONICCE_CONSTANTS_H_
#define _SONICCE_CONSTANTS_H_

//Patterns
#define MV_FIX 0
#define MV_FLY_VERTICAL 1
#define MV_FLY_LEFT 2
#define MV_FLY_RIGHT 3
#define MV_FLY_LEFT_RIGHT 4
#define MV_FLY_RANDOM 5
#define MV_FLY_POURSUIT 6
#define MV_FLY_FLEE 7
#define MV_WALK_PLATFORM 9
#define MV_WALK_LEFT 10
#define MV_WALK_RIGHT 11
#define MV_WALK_POURSUIT 12
#define MV_WALK_FLEE 13

//Actions
#define ACT_NONE 0
#define ACT_SHOOT 1
#define ACT_HIT 2
#define ACT_GIVE_1_RING 3
#define ACT_GIVE_10_RINGS 4
#define ACT_SPEED_BOOST 5
#define ACT_INVINCIBILITY 6
#define ACT_SHIELD 6
#define ACT_ONE_UP 8
#define ACT_FALL 9
#define ACT_DISAPPEAR 10
#define ACT_CHECKPOINT 11
#define ACT1_MASK 0xf0 //0b11110000
#define ACT2_MASK 0x0f //0b00001111

//Action conditions
#define CND_NONE 0
#define CND_SONIC_COLLISION 1
#define CND_SONIC_ATTACK 2
#define CND_SONIC_PRESENCE 3
#define CND_SONIC_COLLISION_TOP 4
#define CND_SONIC_COLLISION_DOWN 5
#define CND_SONIC_COLLISION_LEFT 6
#define CND_SONIC_COLLISION_RIGHT 7
#define CND1_MASK 0xf0 //0b11110000
#define CND2_MASK 0x0f //0b00001111

//rotation indices
#ddefine ROTATION_45 1
#define ROTATION_90 2
#define ROTATION_135 3
#define ROTATION_180 4
#define ROTATION_225 5
#define ROTATION_270 6
#define ROTATION_315 7
#define NO_ROTATION 0

//flip indices
#define NO_MIRROR 0
#define MIRROR_LEFT_RIGHT 1
#define MIRROR_UP_DOWN 2

//collision bitmasks
#define NO_COLLISION 0
#define COLLISION_TOP 1
#define COLLISION_DOWN 2
#define COLLISION_LEFT 4
#define COLLISION_RIGHT 8
#define COLLISION_OBLIQUE_DR 16
#define COLLISION_OBLIQUE_RT 32
#define COLLISION_OBLIQUE_TL 64
#define COLLISION_OBLIQUE_LD 128

//relative position
#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 8
#define IN_UP 16
#define IN_DOWN 32
#define IN_LEFT 64
#define IN_RIGHT 128
#define REL_IN_MASK 0xf0 //0b11110000
#define REL_OUT_MASK 0x0f //0b00001111

//level indices
#define TEST_ZONE 0
#define GRASSY_PLAIN 1
#define SANDY_RUINS 2
#define WINDY_CLIFFS 3
#define GAP_MOUNTAIN 4
#define ICE_DESERT 5
#define METAL_CASTLE 6

////////Level data
#define LEVEL_ITEM_TYPES_NUMBER 32
#define LEVEL_TILE_NUMBER 1728
#define TILEMAP_HEIGHT 36
#define TILEMAP_WIDTH 48
#define TRANSPARENCY 6

//level elements indices and data
#define RING_INDEX 1
#define CHECKPOINT_INDEX 2
#define CHECKPOINT_OK_INDEX 3
#define END_SIGN_INDEX 4
#define END_SIGN_DATA {32,32,MV_FIX,ACT_END_LEVEL<<4,0,CND_SONIC_COLLISION<<4,end_sign_eggman}

//Miscellaneous
#define SONIC_JUMP_STATES_NUMBER 47

//boolean
typedef uint8_t bool;
#define true 1
#define false 0

#endif
