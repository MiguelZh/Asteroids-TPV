#pragma once
#include "GameObjectPool.h"
#include "BlackHole.h"
#include"Vector2D.h"
class BlackHoles : public GameObjectPool<BlackHole,10>
{
public:
	BlackHoles(SDLGame* game);
	virtual ~BlackHoles();
	virtual void receive(const void* senderObj, const msg::Message& msg);
private:
	int nBlackHoles = 0;
	GameObject* fighter_ = nullptr;
	// component for BlackHole
	ImageGC blackHoleImage_;
	RotatingPC rotating_;
};

