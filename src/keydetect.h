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
