#ifndef _SONICCE_GAME_H_
#define _SONICCE_GAME_H_
#include "stdheader.h"
#include "loader.h"

extern level_t* actlevel;
extern sonic_t sonic;

void init_sonic(void);
uint8_t game(void);
void intro_screen(void);
void debug_menu(void);
void game_pause(void);

#endif
