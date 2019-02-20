#pragma once
#include"GameObjectPool.h"
#include"ImageGC.h"
#include"NaturalMovePC.h"
#include"ShowUpAtOppositeSidePC.h"
class Asteroids : public GameObjectPool<Asteroids, 50>
{
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();
private:
	// component for Asteroid
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};

