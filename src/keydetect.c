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
#include "keydetect.h"

bool keyCheck(uint8_t group,uint8_t key)
{
	uint8_t mask;
	mask=kb_ScanGroup(group);
	if(mask&key){
		return true;
	}else{
		return false;
	}
}
