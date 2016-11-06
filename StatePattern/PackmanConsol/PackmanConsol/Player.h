#pragma once
class Player
{
private:
	CVector2 m_position;	//!<座標。
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