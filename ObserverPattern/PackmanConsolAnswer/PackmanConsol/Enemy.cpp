#include "stdafx.h"
#include "PackmanConsol.h"
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy()
{
	//課題ヒント　プレイヤーにリスナーを登録する。
	g_player.AddStateListener(this);
}


Enemy::~Enemy()
{
	//課題ヒント　プレイヤーからリスナーを削除する。
	g_player.RemoveStateListener(this);
}

/*!
*@brief	プレイヤーの描画処理。
*/
void Enemy::Draw()
{
	//フレームバッファにドロー。
	if (m_state == State_Search || m_state == State_Escape) {
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
		//4方向で一番距離が離れる場所に移動する。
		for (auto& move : moveTbl) {
			CVector2 nextPosTmp;
			nextPosTmp = m_position;
			nextPosTmp.Add(move);
			if (nextPos.x >= 0 && nextPos.x < MAP_WIDTH
				&& g_map[nextPosTmp.y][nextPosTmp.x] != 1
				) {
				//壁じゃない&&範囲内
				CVector2 diff;
				diff.x = playerPos.x - nextPosTmp.x;
				diff.y = playerPos.y - nextPosTmp.y;
				int distTmp = diff.x * diff.x + diff.y * diff.y;
				if (distTmp > dist) {
					//こちらのが遠い。
					nextPos = nextPosTmp;
					dist = distTmp;
				}		
			}
		}
		m_position = nextPos;
	}
}