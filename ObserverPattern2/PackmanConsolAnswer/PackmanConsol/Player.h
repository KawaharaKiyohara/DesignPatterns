#pragma once
#include "PlayerBase.h"

class IPlayerStateListener;

class Player : public PlayerBase
{
public:

	/*!
	*@brief	�v���C���[�̕`�揈���B
	*/
	void Draw() override;
	/*!
	*@brief	�v���C���[�̈ړ������B
	*/
	void Move() override;

};

extern Player g_player;