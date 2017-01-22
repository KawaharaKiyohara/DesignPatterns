#pragma once

class IPlayerStateListener {
public:
	virtual ~IPlayerStateListener()
	{

	}
	virtual void NotifyChangeStateInvincible() = 0;
};
