#pragma once

#include "CVector2.h"


//�}�b�v�̍����B
const int MAP_HEIGHT = 15;
//�}�b�v�̕��B
const int MAP_WIDTH = 15;

//�}�b�v�̒�`�B1�͕ǁB0�͉a�B
extern int g_map[MAP_HEIGHT][MAP_WIDTH];

extern char sFrameBuffer[MAP_HEIGHT][MAP_WIDTH];

#include "PathFinding.h"

extern CPathFinding g_pathFinding;

