#ifndef _SONICCE_CONSTANTS_H_
#define _SONICCE_CONSTANTS_H_
//Patterns
#define MV_FIX 0
#define MV_FLY_VERTICAL 1
#define MV_FLY_LEFT 2
#define MV_FLY_RIGHT 3
#define MV_FLY_LEFT_RIGHT 4
#define MV_FLY_RANDOM 5
#define MV_FLY_POURSUIT 6
#define MV_FLY_FLEE 7
#define MV_FALL_AND_UP 8 //les lustres a marble zone
#define MV_WALK_PLATFORM 9
#define MV_WALK_LEFT 10
#define MV_WALK_RIGHT 11
#define MV_WALK_POURSUIT 12
#define MV_WALK_FLEE 13

//Actions
#define ACT_NONE 0
#define ACT_SHOOT 1
#define ACT_HIT 2
#define ACT_GIVE_1_RING 3
#define ACT_GIVE_10_RINGS 4
#define ACT_SPEED_BOOST 5
#define ACT_INVINCIBILITY 6
#define ACT_SHIELD 6
#define ACT_ONE_UP 8
#define ACT_FALL 9
#define ACT_DISAPPEAR 10
#define ACT_CHECKPOINT 11
#define ACT1_MASK 0xf0 //0b11110000
#define ACT2_MASK 0x0f //0b00001111

//Action conditions
#define CND_NONE 0
#define CND_SONIC_COLLISION 1
#define CND_SONIC_ATTACK 2
#define CND_SONIC_PRESENCE 3
#define CND_SONIC_COLLISION_TOP 4
#define CND_SONIC_COLLISION_DOWN 5
#define CND_SONIC_COLLISION_LEFT 6
#define CND_SONIC_COLLISION_RIGHT 7
#define CND1_MASK 0xf0 //0b11110000
#define CND2_MASK 0x0f //0b00001111

//rotation indices
#define ROTATION_90 1
#define ROTATION_180 2
#define ROTATION_270 3
#define NO_ROTATION 0

//flip indices
#define NO_MIRROR 0
#define MIRROR_LEFT_RIGHT 1
#define MIRROR_UP_DOWN 2

//tile collsions indices for masks
#define NONE 0x000000
#define UP 0x000001
#define DOWN 0x000002
#define LEFT 0x000004
#define RIGHT 0x000008
#define IN_UP 0x000010
#define IN_DOWN 0x000020
#define IN_LEFT 0x000040
#define IN_RIGHT 0x000080
#define DGL_UP_RIGHT 0x000100 //diagonals
#define DGL_UP_LEFT 0x000200
#define DGL_DOWN_LEFT 0x000400
#define DGL_DOWN_RIGHT 0x000800
#define MID_UP 0x001000
#define MID_DOWN 0x002000
#define MID_LEFT 0x004000
#define MID_RIGHT 0x008000
#define HALF_DOWN_LEFT 0x010000
#define HALF_DOWN_RIGHT 0x020000

//level indices
#define TEST_ZONE 0
#define GRASSY_PLAIN 1
#define SANDY_RUINS 2
#define WINDY_CLIFFS 3
#define GAP_MOUNTAIN 4
#define ICE_DESERT 5
#define METAL_CASTLE 6

////////Level data
#define LEVEL_ITEM_TYPES_NUMBER 32
#define LEVEL_TILE_NUMBER 120*54
#define TILEMAP_HEIGHT 54
#define TILEMAP_WIDTH 120
#define TRANSPARENCY 6
#define TILE_NUMBER 56

//level elements indices and data
#define RING_INDEX 1
#define CHECKPOINT_INDEX 2
#define CHECKPOINT_OK_INDEX 3
#define END_SIGN_INDEX 4
#define END_SIGN_DATA {32,32,MV_FIX,ACT_END_LEVEL<<4,0,CND_SONIC_COLLISION<<4,end_sign_eggman}

//Miscellaneous
#define JUMP_CONSTANT 6
#define BASE_GRAVITY 2

//boolean
typedef uint8_t bool;
#define true 1
#define false 0

#endif
