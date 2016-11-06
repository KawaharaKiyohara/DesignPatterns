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
*@brief	プレイヤーの描画処理。
*/
void Enemy::Draw()
{
	//フレームバッファにドロー。
	if (m_state == State_Search) {
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'e';
	}
	else if(m_state == State_Tracking){
		sFrameBuffer[m_position.GetY()][m_position.GetX()] = 'E';
	}
}
/*!
*@brief	更新処理。
*/
void Enemy::Update()
{
	if (m_state == State_Search) {
		//徘徊中。
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
			//4×4マス以内にプレイヤーがいる。
			m_state = State_Tracking;
		}
	}
	else if (m_state == State_Tracking) {
		//追跡中。
		m_intervalTime++;
		if (m_intervalTime % 5) {
			return;
		}
		//プレイヤーまでの経路探索。
		std::vector<CVector2> root;
		g_pathFinding.FindRoot(root, m_position, g_player.GetPosition());
		if (!root.empty()) {
			m_position = root[0];
		}
	}
}