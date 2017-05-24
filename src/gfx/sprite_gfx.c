// Converted using ConvPNG
#include <stdint.h>
#include "sprite_gfx.h"

uint16_t sprite_gfx_pal[256] = {
 0x0000,  // 00 :: rgba(0,2,0,255)
 0x2000,  // 01 :: rgba(65,0,3,255)
 0x4000,  // 02 :: rgba(128,0,0,255)
 0x108F,  // 03 :: rgba(33,32,127,255)
 0x6C00,  // 04 :: rgba(226,0,0,255)
 0xA108,  // 05 :: rgba(65,67,65,255)
 0x7C18,  // 06 :: rgba(255,0,200,255)
 0x2114,  // 07 :: rgba(66,63,162,255)
 0x2D97,  // 08 :: rgba(94,97,191,255)
 0x4D88,  // 09 :: rgba(159,96,62,255)
 0x3E0F,  // 10 :: rgba(127,129,126,255)
 0x421B,  // 11 :: rgba(129,128,226,255)
 0x56B5,  // 12 :: rgba(170,172,169,255)
 0x6E8F,  // 13 :: rgba(224,161,127,255)
 0xEF7B,  // 14 :: rgba(222,224,221,255)
 0x2120,  // 15 :: rgba(62,71,0,255)
 0x4A40,  // 16 :: rgba(144,147,0,255)
 0xFFE0,  // 17 :: rgba(255,255,1,255)
 0x0029,  // 18 :: rgba(0,10,76,255)
 0x9400,  // 19 :: rgba(40,4,0,255)
 0x0800,  // 20 :: rgba(17,2,3,255)
 0x9840,  // 21 :: rgba(52,21,0,255)
 0x8060,  // 22 :: rgba(2,30,4,255)
 0x9020,  // 23 :: rgba(35,11,2,255)
 0x8410,  // 24 :: rgba(11,3,135,255)
 0x2440,  // 25 :: rgba(72,18,4,255)
 0x8C66,  // 26 :: rgba(25,30,51,255)
 0x9080,  // 27 :: rgba(30,37,0,255)
 0x00C0,  // 28 :: rgba(0,49,0,255)
 0x2080,  // 29 :: rgba(68,34,0,255)
 0x0D44,  // 30 :: rgba(22,80,30,255)
 0xF39B,  // 31 :: rgba(227,229,225,255)
 0xB0C0,  // 32 :: rgba(102,52,0,255)
 0x8120,  // 33 :: rgba(0,77,0,255)
 0x34A0,  // 34 :: rgba(107,41,0,255)
 0x64A9,  // 35 :: rgba(202,40,76,255)
 0xA12D,  // 36 :: rgba(69,77,107,255)
 0xBD03,  // 37 :: rgba(123,70,22,255)
 0xC500,  // 38 :: rgba(139,70,0,255)
 0x89A0,  // 39 :: rgba(14,110,0,255)
 0x1578,  // 40 :: rgba(43,91,196,255)
 0x9DA0,  // 41 :: rgba(60,110,2,255)
 0xD140,  // 42 :: rgba(165,86,0,255)
 0x0620,  // 43 :: rgba(12,139,2,255)
 0xBA22,  // 44 :: rgba(115,140,13,255)
 0xC9E4,  // 45 :: rgba(147,125,34,255)
 0x1666,  // 46 :: rgba(42,152,51,255)
 0xB9CE,  // 47 :: rgba(115,117,114,255)
 0x6180,  // 48 :: rgba(196,99,0,255)
 0x6138,  // 49 :: rgba(201,71,197,255)
 0xB21C,  // 50 :: rgba(97,132,230,255)
 0x9A80,  // 51 :: rgba(51,165,0,255)
 0xE9C0,  // 52 :: rgba(211,117,0,255)
 0x6A81,  // 53 :: rgba(214,163,10,255)
 0x52C0,  // 54 :: rgba(166,178,0,255)
 0x3E76,  // 55 :: rgba(124,155,183,255)
 0xBA5A,  // 56 :: rgba(114,151,216,255)
 0x22E0,  // 57 :: rgba(67,185,0,255)
 0xF200,  // 58 :: rgba(227,135,0,255)
 0x5F17,  // 59 :: rgba(192,194,190,255)
 0xD31B,  // 60 :: rgba(165,197,226,255)
 0xBF60,  // 61 :: rgba(125,222,0,255)
 0xC6DC,  // 62 :: rgba(143,181,228,255)
 0x5F17,  // 63 :: rgba(192,194,190,255)
 0x48FF,  // 64 :: rgba(148,57,255,255)
 0x61BE,  // 65 :: rgba(198,107,247,255)
 0xEE3E,  // 66 :: rgba(222,140,247,255)
 0xFFED,  // 67 :: rgba(255,255,109,255)
 0x7F69,  // 68 :: rgba(255,219,73,255)
 0x6E44,  // 69 :: rgba(219,146,36,255)
 0x4920,  // 70 :: rgba(146,73,0,255)
 0xFFFF,  // 71 :: rgba(254,255,252,255)
 0xFFFF,  // 72 :: rgba(254,255,252,255)
 0xFFFF,  // 73 :: rgba(254,255,252,255)
 0xFFFF,  // 74 :: rgba(254,255,252,255)
 0xFFFF,  // 75 :: rgba(254,255,252,255)
 0xFFFF,  // 76 :: rgba(254,255,252,255)
 0xFFFF,  // 77 :: rgba(254,255,252,255)
 0xFFFF,  // 78 :: rgba(254,255,252,255)
 0xFFFF,  // 79 :: rgba(254,255,252,255)
 0xFFFF,  // 80 :: rgba(254,255,252,255)
 0xFFFF,  // 81 :: rgba(254,255,252,255)
 0xFFFF,  // 82 :: rgba(254,255,252,255)
 0xFFFF,  // 83 :: rgba(254,255,252,255)
 0xFFFF,  // 84 :: rgba(254,255,252,255)
 0xFFFF,  // 85 :: rgba(254,255,252,255)
 0xFFFF,  // 86 :: rgba(254,255,252,255)
 0xFFFF,  // 87 :: rgba(254,255,252,255)
 0xFFFF,  // 88 :: rgba(254,255,252,255)
 0xFFFF,  // 89 :: rgba(254,255,252,255)
 0xFFFF,  // 90 :: rgba(254,255,252,255)
 0xFFFF,  // 91 :: rgba(254,255,252,255)
 0xFFFF,  // 92 :: rgba(254,255,252,255)
 0xFFFF,  // 93 :: rgba(254,255,252,255)
 0xFFFF,  // 94 :: rgba(254,255,252,255)
 0xFFFF,  // 95 :: rgba(254,255,252,255)
 0xFFFF,  // 96 :: rgba(254,255,252,255)
 0xFFFF,  // 97 :: rgba(254,255,252,255)
 0xFFFF,  // 98 :: rgba(254,255,252,255)
 0xFFFF,  // 99 :: rgba(254,255,252,255)
 0xFFFF,  // 100 :: rgba(254,255,252,255)
 0xFFFF,  // 101 :: rgba(254,255,252,255)
 0xFFFF,  // 102 :: rgba(254,255,252,255)
 0xFFFF,  // 103 :: rgba(254,255,252,255)
 0xFFFF,  // 104 :: rgba(254,255,252,255)
 0xFFFF,  // 105 :: rgba(254,255,252,255)
 0xFFFF,  // 106 :: rgba(254,255,252,255)
 0xFFFF,  // 107 :: rgba(254,255,252,255)
 0xFFFF,  // 108 :: rgba(254,255,252,255)
 0xFFFF,  // 109 :: rgba(254,255,252,255)
 0xFFFF,  // 110 :: rgba(254,255,252,255)
 0xFFFF,  // 111 :: rgba(254,255,252,255)
 0xFFFF,  // 112 :: rgba(254,255,252,255)
 0xFFFF,  // 113 :: rgba(254,255,252,255)
 0xFFFF,  // 114 :: rgba(254,255,252,255)
 0xFFFF,  // 115 :: rgba(254,255,252,255)
 0xFFFF,  // 116 :: rgba(254,255,252,255)
 0xFFFF,  // 117 :: rgba(254,255,252,255)
 0xFFFF,  // 118 :: rgba(254,255,252,255)
 0xFFFF,  // 119 :: rgba(254,255,252,255)
 0xFFFF,  // 120 :: rgba(254,255,252,255)
 0xFFFF,  // 121 :: rgba(254,255,252,255)
 0xFFFF,  // 122 :: rgba(254,255,252,255)
 0xFFFF,  // 123 :: rgba(254,255,252,255)
 0xFFFF,  // 124 :: rgba(254,255,252,255)
 0xFFFF,  // 125 :: rgba(254,255,252,255)
 0xFFFF,  // 126 :: rgba(254,255,252,255)
 0xFFFF,  // 127 :: rgba(254,255,252,255)
 0xFFFF,  // 128 :: rgba(254,255,252,255)
 0xFFFF,  // 129 :: rgba(254,255,252,255)
 0xFFFF,  // 130 :: rgba(254,255,252,255)
 0xFFFF,  // 131 :: rgba(254,255,252,255)
 0xFFFF,  // 132 :: rgba(254,255,252,255)
 0xFFFF,  // 133 :: rgba(254,255,252,255)
 0xFFFF,  // 134 :: rgba(254,255,252,255)
 0xFFFF,  // 135 :: rgba(254,255,252,255)
 0xFFFF,  // 136 :: rgba(254,255,252,255)
 0xFFFF,  // 137 :: rgba(254,255,252,255)
 0xFFFF,  // 138 :: rgba(254,255,252,255)
 0xFFFF,  // 139 :: rgba(254,255,252,255)
 0xFFFF,  // 140 :: rgba(254,255,252,255)
 0xFFFF,  // 141 :: rgba(254,255,252,255)
 0xFFFF,  // 142 :: rgba(254,255,252,255)
 0xFFFF,  // 143 :: rgba(254,255,252,255)
 0xFFFF,  // 144 :: rgba(254,255,252,255)
 0xFFFF,  // 145 :: rgba(254,255,252,255)
 0xFFFF,  // 146 :: rgba(254,255,252,255)
 0xFFFF,  // 147 :: rgba(254,255,252,255)
 0xFFFF,  // 148 :: rgba(254,255,252,255)
 0xFFFF,  // 149 :: rgba(254,255,252,255)
 0xFFFF,  // 150 :: rgba(254,255,252,255)
 0xFFFF,  // 151 :: rgba(254,255,252,255)
 0xFFFF,  // 152 :: rgba(254,255,252,255)
 0xFFFF,  // 153 :: rgba(254,255,252,255)
 0xFFFF,  // 154 :: rgba(254,255,252,255)
 0xFFFF,  // 155 :: rgba(254,255,252,255)
 0xFFFF,  // 156 :: rgba(254,255,252,255)
 0xFFFF,  // 157 :: rgba(254,255,252,255)
 0xFFFF,  // 158 :: rgba(254,255,252,255)
 0xFFFF,  // 159 :: rgba(254,255,252,255)
 0xFFFF,  // 160 :: rgba(254,255,252,255)
 0xFFFF,  // 161 :: rgba(254,255,252,255)
 0xFFFF,  // 162 :: rgba(254,255,252,255)
 0xFFFF,  // 163 :: rgba(254,255,252,255)
 0xFFFF,  // 164 :: rgba(254,255,252,255)
 0xFFFF,  // 165 :: rgba(254,255,252,255)
 0xFFFF,  // 166 :: rgba(254,255,252,255)
 0xFFFF,  // 167 :: rgba(254,255,252,255)
 0xFFFF,  // 168 :: rgba(254,255,252,255)
 0xFFFF,  // 169 :: rgba(254,255,252,255)
 0xFFFF,  // 170 :: rgba(254,255,252,255)
 0xFFFF,  // 171 :: rgba(254,255,252,255)
 0xFFFF,  // 172 :: rgba(254,255,252,255)
 0xFFFF,  // 173 :: rgba(254,255,252,255)
 0xFFFF,  // 174 :: rgba(254,255,252,255)
 0xFFFF,  // 175 :: rgba(254,255,252,255)
 0xFFFF,  // 176 :: rgba(254,255,252,255)
 0xFFFF,  // 177 :: rgba(254,255,252,255)
 0xFFFF,  // 178 :: rgba(254,255,252,255)
 0xFFFF,  // 179 :: rgba(254,255,252,255)
 0xFFFF,  // 180 :: rgba(254,255,252,255)
 0xFFFF,  // 181 :: rgba(254,255,252,255)
 0xFFFF,  // 182 :: rgba(254,255,252,255)
 0xFFFF,  // 183 :: rgba(254,255,252,255)
 0xFFFF,  // 184 :: rgba(254,255,252,255)
 0xFFFF,  // 185 :: rgba(254,255,252,255)
 0xFFFF,  // 186 :: rgba(254,255,252,255)
 0xFFFF,  // 187 :: rgba(254,255,252,255)
 0xFFFF,  // 188 :: rgba(254,255,252,255)
 0xFFFF,  // 189 :: rgba(254,255,252,255)
 0xFFFF,  // 190 :: rgba(254,255,252,255)
 0xFFFF,  // 191 :: rgba(254,255,252,255)
 0xFFFF,  // 192 :: rgba(254,255,252,255)
 0xFFFF,  // 193 :: rgba(254,255,252,255)
 0xFFFF,  // 194 :: rgba(254,255,252,255)
 0xFFFF,  // 195 :: rgba(254,255,252,255)
 0xFFFF,  // 196 :: rgba(254,255,252,255)
 0xFFFF,  // 197 :: rgba(254,255,252,255)
 0xFFFF,  // 198 :: rgba(254,255,252,255)
 0xFFFF,  // 199 :: rgba(254,255,252,255)
 0xFFFF,  // 200 :: rgba(254,255,252,255)
 0xFFFF,  // 201 :: rgba(254,255,252,255)
 0xFFFF,  // 202 :: rgba(254,255,252,255)
 0xFFFF,  // 203 :: rgba(254,255,252,255)
 0xFFFF,  // 204 :: rgba(254,255,252,255)
 0xFFFF,  // 205 :: rgba(254,255,252,255)
 0xFFFF,  // 206 :: rgba(254,255,252,255)
 0xFFFF,  // 207 :: rgba(254,255,252,255)
 0xFFFF,  // 208 :: rgba(254,255,252,255)
 0xFFFF,  // 209 :: rgba(254,255,252,255)
 0xFFFF,  // 210 :: rgba(254,255,252,255)
 0xFFFF,  // 211 :: rgba(254,255,252,255)
 0xFFFF,  // 212 :: rgba(254,255,252,255)
 0xFFFF,  // 213 :: rgba(254,255,252,255)
 0xFFFF,  // 214 :: rgba(254,255,252,255)
 0xFFFF,  // 215 :: rgba(254,255,252,255)
 0xFFFF,  // 216 :: rgba(254,255,252,255)
 0xFFFF,  // 217 :: rgba(254,255,252,255)
 0xFFFF,  // 218 :: rgba(254,255,252,255)
 0xFFFF,  // 219 :: rgba(254,255,252,255)
 0xFFFF,  // 220 :: rgba(254,255,252,255)
 0xFFFF,  // 221 :: rgba(254,255,252,255)
 0xFFFF,  // 222 :: rgba(254,255,252,255)
 0xFFFF,  // 223 :: rgba(254,255,252,255)
 0xFFFF,  // 224 :: rgba(254,255,252,255)
 0xFFFF,  // 225 :: rgba(254,255,252,255)
 0xFFFF,  // 226 :: rgba(254,255,252,255)
 0xFFFF,  // 227 :: rgba(254,255,252,255)
 0xFFFF,  // 228 :: rgba(254,255,252,255)
 0xFFFF,  // 229 :: rgba(254,255,252,255)
 0xFFFF,  // 230 :: rgba(254,255,252,255)
 0xFFFF,  // 231 :: rgba(254,255,252,255)
 0xFFFF,  // 232 :: rgba(254,255,252,255)
 0xFFFF,  // 233 :: rgba(254,255,252,255)
 0xFFFF,  // 234 :: rgba(254,255,252,255)
 0xFFFF,  // 235 :: rgba(254,255,252,255)
 0xFFFF,  // 236 :: rgba(254,255,252,255)
 0xFFFF,  // 237 :: rgba(254,255,252,255)
 0xFFFF,  // 238 :: rgba(254,255,252,255)
 0xFFFF,  // 239 :: rgba(254,255,252,255)
 0xFFFF,  // 240 :: rgba(254,255,252,255)
 0xFFFF,  // 241 :: rgba(254,255,252,255)
 0xFFFF,  // 242 :: rgba(254,255,252,255)
 0xFFFF,  // 243 :: rgba(254,255,252,255)
 0xFFFF,  // 244 :: rgba(254,255,252,255)
 0xFFFF,  // 245 :: rgba(254,255,252,255)
 0xFFFF,  // 246 :: rgba(254,255,252,255)
 0xFFFF,  // 247 :: rgba(254,255,252,255)
 0xFFFF,  // 248 :: rgba(254,255,252,255)
 0xFFFF,  // 249 :: rgba(254,255,252,255)
 0xFFFF,  // 250 :: rgba(254,255,252,255)
 0xFFFF,  // 251 :: rgba(254,255,252,255)
 0xFFFF,  // 252 :: rgba(254,255,252,255)
 0xFFFF,  // 253 :: rgba(254,255,252,255)
 0xFFFF,  // 254 :: rgba(254,255,252,255)
 0xFFFF,  // 255 :: rgba(254,255,252,255)
};