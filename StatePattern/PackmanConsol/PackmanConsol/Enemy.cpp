#include "stdafx.h"
#include "PackmanConsol.h"
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

/*!
*@brief	�v���C���[�̕`�揈���B
*/
void Enemy::Draw()
{
	//�t���[���o�b�t�@�Ƀh���[�B
	if (m_state == State_Search) {
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'e';
	}
	else if(m_state == State_Tracking){
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'E';
	}
}
/*!
*@brief	�X�V�����B
*/
void Enemy::Update()
{
	if (m_state == State_Search) {
		//�p�j���B
		m_intervalTime++;
		if (m_intervalTime % 5) {
			return;
		}
		m_position.x += m_moveDir;
		m_moveDir *= -1;
		CVector2 playerPos = g_player.GetPosition();
		if (abs(playerPos.x - m_position.x) < 4
			&& abs(playerPos.y - m_position.y) < 4
			) {
			//4�~4�}�X�ȓ��Ƀv���C���[������B
			m_state = State_Tracking;
		}
	}
	else if (m_state == State_Tracking) {
		//�ǐՒ��B
		m_intervalTime++;
		if (m_intervalTime % 5) {
			return;
		}
		//�v���C���[�܂ł̌o�H�T���B
		std::vector<CVector2> root;
		g_pathFinding.FindRoot(root, m_position, g_player.GetPosition());
		if (!root.empty()) {
			m_position = root[0];
		}
	}
}