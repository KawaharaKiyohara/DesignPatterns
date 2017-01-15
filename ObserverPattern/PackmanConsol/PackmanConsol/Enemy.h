#pragma once
//課題ヒント エネミークラスは状態変化の通知を受けるConcreteObserverクラスなのでObserberクラスを継承する必要がある。
class Enemy
{
	//状態。
	enum State {
		State_Search,		//徘徊中。
		State_Tracking,		//追尾中	
		State_Escape,		//逃走中。
	};
	CVector2 m_position;				//!<座標。
	int		m_moveDir = 1;				//!<移動方向
	int		m_intervalTime;
	State	m_state = State_Search;		//!<状態を表す変数。
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

