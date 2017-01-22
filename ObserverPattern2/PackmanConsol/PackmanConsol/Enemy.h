#pragma once
#include "IPlayerStateListener.h"
//�ۑ�q���g �G�l�~�[�N���X�͏�ԕω��̒ʒm���󂯂�ConcreteObserver�N���X�Ȃ̂�Obserber�N���X���p������K�v������B
class Enemy : public IPlayerStateListener
{
	//��ԁB
	enum State {
		State_Search,		//�p�j���B
		State_Tracking,		//�ǔ���	
		State_Escape,		//�������B
	};
	CVector2 m_position;				//!<���W�B
	int		m_moveDir = 1;				//!<�ړ�����
	int		m_intervalTime;
	State	m_state = State_Search;		//!<��Ԃ�\���ϐ��B
public:
	Enemy();
	~Enemy();
	void Draw();
	void Update();
	void NotifyChangeStateInvincible()
	{
		//�X�e�[�g�𓦑����ɕύX�B
		m_state = State_Escape;
	}
	void SetPosition(int x, int y)
	{
		m_position.Set(x, y);
	}
};

