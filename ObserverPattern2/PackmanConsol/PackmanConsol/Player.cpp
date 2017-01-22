#include "stdafx.h"
#include "Player.h"
#include "IPlayerStateListener.h"

Player g_player;


/*!
*@brief	�v���C���[�̕`�揈���B
*/
void Player::Draw()
{
	//�t���[���o�b�t�@�Ƀh���[�B
	//�ۑ�q���g�@�`�悳���镶����Player��Player2�ƂňقȂ��Ă���B
	if (m_isPowerUp) {
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'P';
	}
	else {
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'p';
	}
}
/*!
*@brief	�X�V�����B
*/
void Player::Update()
{
	//�ۑ�q���g�@�ړ������鏈����Player��Player2�ƂňقȂ��Ă���B
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
	if (g_map[y][x] == 3 && !m_isPowerUp) {
		//�p���[�A�b�v�A�C�e����H�ׂ��̂Ńp���[�A�b�v�t���O�𗧂Ă�B
		//�ۑ�q���g �����Ńv���C���[�X�e�[�g���X�i�[�ɑ΂��ăp���[�A�b�v�������Ƃ�ʒm���Ă��΂����B
		for (auto listener : m_stateChangeListener) {
			listener->NotifyChangeStateInvincible();
		}
		m_isPowerUp = true;
	}
}
