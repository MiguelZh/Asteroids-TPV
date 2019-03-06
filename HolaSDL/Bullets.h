#pragma once
#include "NaturalMovePC.h"
#include"ImageGC.h"
#include"GameObjectPool.h"
#include"Bullet.h"
#include "DeactivateOnBorderExit.h"
class Bullets :public GameObjectPool<Bullet,10>
{
public:
	Bullets(SDLGame * game);
	virtual ~Bullets();
	void shootBullet();
private:
	// components for Bullet
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;
	virtual void handleInput(Uint32 time, const SDL_Event& event);

};

