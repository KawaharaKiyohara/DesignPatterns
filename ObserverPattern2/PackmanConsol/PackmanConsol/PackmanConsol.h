#pragma once

#include "CVector2.h"


//マップの高さ。
const int MAP_HEIGHT = 15;
//マップの幅。
const int MAP_WIDTH = 15;

//マップの定義。1は壁。0は餌。
extern int g_map[MAP_HEIGHT][MAP_WIDTH];

extern char sFrameBuffer[MAP_HEIGHT][MAP_WIDTH];

#include "PathFinding.h"

extern CPathFinding g_pathFinding;

