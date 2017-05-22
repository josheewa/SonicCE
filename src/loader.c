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
#include "loader.h"
#include "gfx/sprite_gfx.h"
#include "gfx/tile_gfx.h"

gfx_image_t* sonic_standby;
gfx_image_t* sonic_look_up;
gfx_image_t* sonic_look_down;
gfx_image_t* sonic_ball;
gfx_image_t* sonic_hit;
gfx_image_t* sonic_dead;
gfx_image_t* sonic_push;
gfx_image_t* sonic_run_1;
gfx_image_t* sonic_run_2;
gfx_image_t* sonic_run_wall_1;
gfx_image_t* sonic_run_wall_2;
gfx_image_t* sonic_walk_1;
gfx_image_t* sonic_walk_2;
gfx_image_t* sonic_walk_3;
gfx_image_t* sonic_walk_wall_1;
gfx_image_t* sonic_walk_wall_2;
gfx_image_t* sonic_walk_wall_3;
gfx_image_t* ring;
gfx_image_t* checkpoint;
gfx_image_t* checkpoint_ok;
gfx_image_t* ressort;
gfx_image_t* ressort_act;
gfx_image_t* end_sign_eggman;
gfx_image_t* end_sign_eggman_turn;
gfx_image_t* end_sign_profil;
gfx_image_t* end_sign_eggman_turn_3;
gfx_image_t* end_sign_sonic;
gfx_image_t* introellipsis;

el_info_t RING_DATA={10,10,MV_FIX,(ACT_GIVE_1_RING<<4)+ACT_DISAPPEAR,0,CND_SONIC_COLLISION<<4+CND_SONIC_COLLISION,0};
el_info_t CHECKPOINT_DATA={11,42,MV_FIX,ACT_CHECKPOINT<<4,0,CND_SONIC_COLLISION<<4,0};
el_info_t CHECKPOINT_OK_DATA={11,42,MV_FIX,0,0,0,0};

uint8_t progression[2];
ti_var_t file_var;
el_info_t item_desc[LEVEL_ITEM_TYPES_NUMBER];
level_t level_to_load;
gfx_tilemap_t tilemap;
uint24_t i;
gfx_image_t* tileset_tiles[56];
uint8_t level[LEVEL_TILE_NUMBER];

void loadSprites(void)
{
	sonic_standby=gfx_MallocSprite(19, 26);
	dzx7_Standard(sonic_standby_compressed, sonic_standby);
	sonic_look_up=gfx_MallocSprite(19, 25);
	dzx7_Standard(sonic_look_up_compressed, sonic_look_up);
	sonic_look_down=gfx_MallocSprite(19, 17);
	dzx7_Standard(sonic_look_down_compressed, sonic_look_down);
	sonic_ball=gfx_MallocSprite(20, 20);
	dzx7_Standard(sonic_ball_compressed, sonic_ball);
	sonic_hit=gfx_MallocSprite(27, 19);
	dzx7_Standard(sonic_hit_compressed, sonic_hit);
	sonic_dead=gfx_MallocSprite(23, 29);
	dzx7_Standard(sonic_dead_compressed, sonic_dead);
	sonic_push=gfx_MallocSprite(19, 24);
	dzx7_Standard(sonic_push_compressed, sonic_push);
	////////
	sonic_run_1=gfx_MallocSprite(20, 23);
	dzx7_Standard(sonic_run_1_compressed, sonic_run_1);
	sonic_run_2=gfx_MallocSprite(21, 24);
	dzx7_Standard(sonic_run_2_compressed, sonic_run_2);
	sonic_run_wall_1=gfx_MallocSprite(26, 24);
	dzx7_Standard(sonic_run_wall_1_compressed, sonic_run_wall_1);
	sonic_run_wall_2=gfx_MallocSprite(27, 24);
	dzx7_Standard(sonic_run_wall_2_compressed, sonic_run_wall_2);
	////////
	sonic_walk_1=gfx_MallocSprite(24, 25);
	dzx7_Standard(sonic_walk_1_compressed, sonic_walk_1);
	sonic_walk_2=gfx_MallocSprite(19, 25);
	dzx7_Standard(sonic_walk_2_compressed, sonic_walk_2);
	sonic_walk_3=gfx_MallocSprite(25, 25);
	dzx7_Standard(sonic_walk_3_compressed, sonic_walk_3);
	sonic_walk_wall_1=gfx_MallocSprite(29, 24);
	dzx7_Standard(sonic_walk_wall_1_compressed, sonic_walk_wall_1);
	sonic_walk_wall_2=gfx_MallocSprite(25, 25);
	dzx7_Standard(sonic_walk_wall_2_compressed, sonic_walk_wall_2);
	sonic_walk_wall_3=gfx_MallocSprite(28, 25);
	dzx7_Standard(sonic_walk_wall_3_compressed, sonic_walk_wall_3);
	////////
	ring=gfx_MallocSprite(10, 10);
	dzx7_Standard(ring_compressed, ring);
	checkpoint=gfx_MallocSprite(11, 42);
	dzx7_Standard(checkpoint_compressed, checkpoint);
	checkpoint_ok=gfx_MallocSprite(11, 42);
	dzx7_Standard(checkpoint_ok_compressed, checkpoint_ok);
	ring=gfx_MallocSprite(10, 10);
	dzx7_Standard(ring_compressed, ring);
	checkpoint=gfx_MallocSprite(11, 42);
	dzx7_Standard(checkpoint_compressed, checkpoint);
	checkpoint_ok=gfx_MallocSprite(11, 42);
	dzx7_Standard(checkpoint_ok_compressed, checkpoint_ok);
	ressort=gfx_MallocSprite(18, 10);
	dzx7_Standard(ressort_compressed, ressort);
	ressort_act=gfx_MallocSprite(18, 21);
	dzx7_Standard(ressort_act_compressed, ressort_act);
	////////
	introellipsis=gfx_MallocSprite(25, 30);
	dzx7_Standard(introellipsis_compressed, introellipsis);
}

void loadSave(void)
{
	ti_CloseAll();
	file_var=ti_Open("SoniSAV","r");
	if(!file_var)
	{
		progression[0]=1;
		progression[1]=1;
		saveProgress();
	}
	if(!ti_Read(&progression, sizeof(uint8_t)*2, 1, file_var))
	{
		progression[0]=1;
		progression[1]=1;
		saveProgress();
	}
	ti_CloseAll();
	//debug!!!!
	progression[0]=0;
	progression[1]=1;
	//end of debugging section
}

void saveProgress(void)
{
	ti_CloseAll();
	file_var=ti_Open("SoniSAV","w");
	ti_Write(&progression, sizeof(uint8_t)*2, 1, file_var);
	ti_CloseAll();
}

void loadGameData(void){
	RING_DATA.sprite=ring;
	CHECKPOINT_DATA.sprite=checkpoint;
	CHECKPOINT_OK_DATA.sprite=checkpoint_ok;
	item_desc[RING_INDEX]=RING_DATA;
	item_desc[CHECKPOINT_INDEX]=CHECKPOINT_DATA;
	item_desc[CHECKPOINT_OK_INDEX]=CHECKPOINT_OK_DATA;
}

level_t* loadLevel()
{
	char varnum[8]="SoniLV";
	switch(progression[0])
	{
		case TEST_ZONE:
			varnum[6]='0';
			break;
		case GRASSY_PLAIN:
			varnum[6]='1';
			break;
		case SANDY_RUINS:
			varnum[6]='2';
			break;
		case WINDY_CLIFFS:
			varnum[6]='3';
			break;
		case GAP_MOUNTAIN:
			varnum[6]='4';
			break;
		case ICE_DESERT:
			varnum[6]='5';
			break;
		case METAL_CASTLE:
			varnum[6]='6';
			break;
		default:
			varnum[6]='1';
			progression[0]=GRASSY_PLAIN;
			break;
	}
	switch(progression[1])
	{
		case 1:
			varnum[7]='1';
			break;
		case 2:
			varnum[7]='2';
			break;
		case 3:
			varnum[7]='3';
			break;
		default:
			varnum[7]='1';
			progression[0]=1;
			break;
	}
	ti_CloseAll();
	file_var=ti_Open(varnum,"r");
	if(!file_var)
		return NULL;
	if(!ti_Read(&level_to_load, sizeof(level_t), 1, file_var))
		return NULL;
	ti_CloseAll();
	gfx_palette[TRANSPARENCY]=gfx_palette[level_to_load.bg_color];
	return &level_to_load;
}

void copyTable(uint8_t* table1, uint8_t* table2, uint8_t len)
{
	for(i=0;i<len;i++)
	{
		table2[i]=table1[i];
	}
}

void getLevel(uint8_t index)
{
	switch(index)
	{
		case 0x01:
			copyTable(&level,&SoniLV01,LEVEL_TILE_NUMBER);
			break;
		default:
			copyTable(&level,&SoniLV01,LEVEL_TILE_NUMBER);
			break;
	}
}

void loadTiles(void)
{
	gfx_image_t *tmp_ptr;
	/* Decompress the tiles */
	for(i = 0; i < 56; i++){
		tmp_ptr = gfx_MallocSprite(32,32);
		dzx7_Turbo(tileset_tiles_compressed[i], tmp_ptr);
		tileset_tiles[i]=tmp_ptr;
	}
}
