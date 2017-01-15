#include "stdafx.h"
#include "PackmanConsol.h"
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy()
{
	//�ۑ�q���g�@�v���C���[�Ƀ��X�i�[��o�^����B
	g_player.AddStateListener(this);
}


Enemy::~Enemy()
{
	//�ۑ�q���g�@�v���C���[���烊�X�i�[���폜����B
	g_player.RemoveStateListener(this);
}

/*!
*@brief	�v���C���[�̕`�揈���B
*/
void Enemy::Draw()
{
	//�t���[���o�b�t�@�Ƀh���[�B
	if (m_state == State_Search || m_state == State_Escape) {
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
	else if (m_state == State_Escape) {
		m_intervalTime++;
		if (m_intervalTime % 5) {
			return;
		}
		
		
		CVector2 playerPos = g_player.GetPosition();
		static CVector2 moveTbl[] =
		{
			{ 1, 0 },
			{-1, 0 },
			{ 0, 1 },
			{ 0,-1 },
		};
		int dist = 0;
		CVector2 nextPos = m_position;
		//4�����ň�ԋ����������ꏊ�Ɉړ�����B
		for (auto& move : moveTbl) {
			CVector2 nextPosTmp;
			nextPosTmp = m_position;
			nextPosTmp.Add(move);
			if (nextPos.x >= 0 && nextPos.x < MAP_WIDTH
				&& g_map[nextPosTmp.y][nextPosTmp.x] != 1
				) {
				//�ǂ���Ȃ�&&�͈͓�
				CVector2 diff;
				diff.x = playerPos.x - nextPosTmp.x;
				diff.y = playerPos.y - nextPosTmp.y;
				int distTmp = diff.x * diff.x + diff.y * diff.y;
				if (distTmp > dist) {
					//������̂������B
					nextPos = nextPosTmp;
					dist = distTmp;
				}		
			}
		}
		m_position = nextPos;
	}
}