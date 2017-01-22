#pragma once

class IPlayerStateListener;

class PlayerBase
{

protected:
	CVector2 m_position;		//!<���W�B
	bool m_isPowerUp = false;	//!<�p���[�A�b�v���H
								//�ۑ�q���g Player�N���X�͏�ԕω����Ď����郊�X�i�[�̃��X�g��ێ����Ă���͂��B
	std::vector<IPlayerStateListener*> m_stateChangeListener;
public:


	/*!
	*@brief	�R���X�g���N�^�B
	*/
	PlayerBase()
	{
		//���������s���B
		m_position.Set(0, 0);
	}
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~PlayerBase()
	{

	}
	void AddStateListener(IPlayerStateListener* listener)
	{
		m_stateChangeListener.push_back(listener);
	}

	void RemoveStateListener(IPlayerStateListener* listener)
	{
		//�폜���郊�X�i�[�������B
		auto delObj = std::find(m_stateChangeListener.begin(), m_stateChangeListener.end(), listener);
		if (delObj != m_stateChangeListener.end()) {
			//�폜����I�u�T�[�o�[�����������B
			m_stateChangeListener.erase(delObj);
		}
	}

	/*!
	*@brief	�v���C���[�̕`�揈���B
	*/
	virtual void Draw() = 0;
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
	/*!
	*@brief �p���[�A�b�v���Ă��邩����B
	*/
	bool IsPowerUp() const
	{
		return m_isPowerUp;
	}
private:
	/*!
	*@brief �ړ������B
	*/
	virtual void Move() = 0;
};

extern PlayerBase* playerList[2];

