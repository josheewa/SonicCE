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
#ifndef _LOADER_H_
#define _LOADER_H_
#include "common.h"
#include "game.h"

extern gfx_image_t* sonic_standby;
extern gfx_image_t* sonic_look_up;
extern gfx_image_t* sonic_look_down;
extern gfx_image_t* sonic_ball;
extern gfx_image_t* sonic_hit;
extern gfx_image_t* sonic_dead;
extern gfx_image_t* sonic_push;
extern gfx_image_t* sonic_run_1;
extern gfx_image_t* sonic_run_2;
extern gfx_image_t* sonic_run_wall_1;
extern gfx_image_t* sonic_run_wall_2;
extern gfx_image_t* sonic_walk_1;
extern gfx_image_t* sonic_walk_2;
extern gfx_image_t* sonic_walk_3;
extern gfx_image_t* sonic_walk_wall_1;
extern gfx_image_t* sonic_walk_wall_2;
extern gfx_image_t* sonic_walk_wall_3;
extern gfx_image_t* ring;
extern gfx_image_t* checkpoint;
extern gfx_image_t* checkpoint_ok;
extern gfx_image_t* ressort;
extern gfx_image_t* ressort_act;
extern gfx_image_t* end_sign_eggman;
extern gfx_image_t* end_sign_eggman_turn;
extern gfx_image_t* end_sign_profil;
extern gfx_image_t* end_sign_eggman_turn_3;
extern gfx_image_t* end_sign_sonic;
extern gfx_image_t* introellipsis;

extern uint8_t progression[2];
extern el_info_t item_desc[LEVEL_ITEM_TYPES_NUMBER];
extern gfx_tilemap_t tilemap;

void loadSprites(void);
void loadSave(void);
void saveProgress(void);
void loadGameData(void);
level_t* loadLevel(void);
void loadTiles(void);
#endif
