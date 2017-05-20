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
