#ifndef _SONICCE_GAME_H_
#define _SONICCE_GAME_H_
#include "common.h"
#include "loader.h"
#include "keydetect.h"

extern level_t* actlevel;

void initSonic(void);
uint8_t game(void);
void introScreen(void);

#endif
