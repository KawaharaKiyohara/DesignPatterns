#pragma once
class Enemy
{
	//��ԁB
	enum State {
		State_Search,		//�p�j���B
		State_Tracking,		//�ǔ���	
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
	void SetPosition(int x, int y)
	{
		m_position.Set(x, y);
	}
};

