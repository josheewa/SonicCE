#ifndef _LOADER_H_
#define _LOADER_H_
#include "stdheader.h"
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
extern gfx_image_t* tileset_tiles[56];

void unload_sprites(void);
void load_sprites(void);
void load_save(void);
uint8_t save_progress(void);
void load_game_data(void);
level_t* load_level(void);
void load_tilemap(void num);
#endif
