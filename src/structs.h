#ifndef _SONICCE_STRUCTS_H_
#define _SONICCE_STRUCTS_H_
#include "stdheader.h"

typedef struct save_s{
	uint8_t level;
	uint8_t act;
} save_t;

typedef struct box_s{
	int x;
	int y;
	uint8_t w;
	uint8_t h;
} box_t;

typedef struct point_s{
	uint16_t x;
	uint8_t y;
} point_t;

typedef struct sonic_s{
	box_t box;
	int speed;
	gfx_image_t* actsprite;
	uint8_t spr_mirror;
	uint8_t gravity;
	bool jumping;
} sonic_t;

typedef struct el_info_s{
	uint8_t width;
	uint8_t height;
	uint8_t pattern;
	uint8_t collision;
	uint8_t actions;
	uint8_t actions_frequence;
	uint8_t actions_condition;
	gfx_image_t* sprite;
} el_info_t;

typedef struct element_s{
	box_t box;
	uint8_t spr_mirror;
	uint8_t spr_rotation;
} element_t;

typedef struct el_saved_s{
	uint8_t num;
	uint8_t tile_x;
	uint8_t tile_y;
} el_saved_t;

typedef struct tile_s{
	box_t box;
	uint8_t collision;
	uint8_t tile_rotation;
	uint8_t sonic_rotation;
	gfx_image_t* actsprite;
} tile_t;

typedef struct level_s{
	uint8_t leveldex;
	uint8_t bg_color;
	char name[16];
	uint8_t act_number;
	uint8_t depart_tile_x;
	uint8_t depart_tile_y;
	uint8_t data[LEVEL_TILE_NUMBER];
	el_saved_t items[128];
} level_t;
#endif
