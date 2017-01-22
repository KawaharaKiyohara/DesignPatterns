#pragma once
#include "PlayerBase.h"

class IPlayerStateListener;

class Player2 : public PlayerBase
{
	
public:
	
	/*!
	*@brief	プレイヤーの描画処理。
	*/
	void Draw() override;
	/*!
	*@brief	プレイヤーの移動処理。
	*/
	void Move() override;
};

extern Player2 g_player2;