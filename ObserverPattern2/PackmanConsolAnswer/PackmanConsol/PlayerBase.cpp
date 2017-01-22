#include "stdafx.h"
#include "PlayerBase.h"
#include "IPlayerStateListener.h"

PlayerBase* playerList[2];

/*!
*@brief	�X�V�����B
*/
void PlayerBase::Update()
{
	Move();
	
	if (g_map[m_position.GetY()][m_position.GetX()] == 3 && !m_isPowerUp) {
		//�p���[�A�b�v�A�C�e����H�ׂ��̂Ńp���[�A�b�v�t���O�𗧂Ă�B
		//�ۑ�q���g �����Ńv���C���[�X�e�[�g���X�i�[�ɑ΂��ăp���[�A�b�v�������Ƃ�ʒm���Ă��΂����B
		for (auto listener : m_stateChangeListener) {
			listener->NotifyChangeStateInvincible();
		}
		m_isPowerUp = true;
	}
}