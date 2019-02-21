#pragma once
#include"GameObjectPool.h"
#include"Asteroid.h"
#include"Vector2D.h"
class Asteroids : public GameObjectPool<Asteroid, 50>
{
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
private:
	// component for Asteroid
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};

