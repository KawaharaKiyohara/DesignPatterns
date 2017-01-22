#include "stdafx.h"
#include "Player.h"
#include "IPlayerStateListener.h"

Player g_player;


/*!
*@brief	プレイヤーの描画処理。
*/
void Player::Draw()
{
	//フレームバッファにドロー。
	if (m_isPowerUp) {
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'P';
	}
	else {
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'p';
	}
}
void Player::Move()
{
	int x = m_position.GetX();
	int y = m_position.GetY();
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		y--;
		if (y < 0) {
			y = 0;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		x--;
		if (x < 0) {
			x = 0;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		y++;
		if (y > MAP_HEIGHT - 1) {
			y = MAP_HEIGHT - 1;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		x++;
		if (x > MAP_WIDTH - 1) {
			x = MAP_WIDTH - 1;
		}
	}
	if (g_map[y][x] != 1) {
		m_position.Set(x, y);
	}
}