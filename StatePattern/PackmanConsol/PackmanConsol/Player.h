#pragma once
class Player
{
private:
	CVector2 m_position;	//!<���W�B
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Player()
	{
		//���������s���B
		m_position.Set(0, 0);
	}
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~Player()
	{

	}
	/*!
	*@brief	�v���C���[�̕`�揈���B
	*/
	void Draw();
	/*!
	*@brief	�X�V�����B
	*/
	void Update();
	CVector2 GetPosition()
	{
		return m_position;
	}
	/*!
	*@brief	X���W���擾�B
	*/
	int GetPositionX()
	{
		return m_position.GetX();
	}
	/*!
	*@brief	Y���W���擾�B
	*/
	int GetPositionY()
	{
		return m_position.GetY();
	}
	/*!
	*@brief	���W��ݒ�B
	*@param	x		x���W�B
	*@param	y		y���W�B
	*/
	void SetPosition(int x, int y)
	{
		m_position.Set(x, y);
	}
};

extern Player g_player;