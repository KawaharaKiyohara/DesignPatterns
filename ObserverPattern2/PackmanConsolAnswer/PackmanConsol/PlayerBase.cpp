#include "stdafx.h"
#include "PlayerBase.h"
#include "IPlayerStateListener.h"

PlayerBase* playerList[2];

/*!
*@brief	更新処理。
*/
void PlayerBase::Update()
{
	Move();
	
	if (g_map[m_position.GetY()][m_position.GetX()] == 3 && !m_isPowerUp) {
		//パワーアップアイテムを食べたのでパワーアップフラグを立てる。
		//課題ヒント ここでプレイヤーステートリスナーに対してパワーアップしたことを通知してやればいい。
		for (auto listener : m_stateChangeListener) {
			listener->NotifyChangeStateInvincible();
		}
		m_isPowerUp = true;
	}
}