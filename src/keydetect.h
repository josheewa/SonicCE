#ifndef _SONICCE_KEYDETECT_H_
#define _SONICCE_KEYDETECT_H_
#include "common.h"
#define annul kb_Clear
#define second kb_2nd
#define alpha kb_Alpha
#define up kb_Up
#define down kb_Down
#define right kb_Right
#define left kb_Left
#define second_group kb_group_1
#define alpha_group kb_group_2
#define annul_group kb_group_6
#define dir_group kb_group_7

bool keyCheck(uint8_t group, uint8_t key);
#endif
