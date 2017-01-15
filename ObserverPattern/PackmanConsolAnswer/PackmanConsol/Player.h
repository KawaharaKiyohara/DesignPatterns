#pragma once

class IPlayerStateListener;

class Player
{
private:
	CVector2 m_position;		//!<座標。
	bool m_isPowerUp = false;	//!<パワーアップ中？
	//課題ヒント Playerクラスは状態変化を監視するリスナーのリストを保持しているはず。
	std::vector<IPlayerStateListener*> m_stateChangeListener;
public:
	/*!
	*@brief	コンストラクタ。
	*/
	Player()
	{
		//初期化を行う。
		m_position.Set(0, 0);
	}
	/*!
	*@brief	デストラクタ。
	*/
	~Player()
	{

	}
	void Player::AddStateListener(IPlayerStateListener* listener)
	{
		m_stateChangeListener.push_back(listener);
	}

	void Player::RemoveStateListener(IPlayerStateListener* listener)
	{
		//削除するリスナーを検索。
		auto delObj = std::find(m_stateChangeListener.begin(), m_stateChangeListener.end(), listener);
		if (delObj != m_stateChangeListener.end()) {
			//削除するオブサーバーが見つかった。
			m_stateChangeListener.erase(delObj);
		}
	}

	/*!
	*@brief	プレイヤーの描画処理。
	*/
	void Draw();
	/*!
	*@brief	更新処理。
	*/
	void Update();
	CVector2 GetPosition()
	{
		return m_position;
	}
	/*!
	*@brief	X座標を取得。
	*/
	int GetPositionX()
	{
		return m_position.GetX();
	}
	/*!
	*@brief	Y座標を取得。
	*/
	int GetPositionY()
	{
		return m_position.GetY();
	}
	/*!
	*@brief	座標を設定。
	*@param	x		x座標。
	*@param	y		y座標。
	*/
	void SetPosition(int x, int y)
	{
		m_position.Set(x, y);
	}
};

extern Player g_player;