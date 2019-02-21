#pragma once
#include"GameObjectPool.h"
#include"Asteroid.h"
#include"Vector2D.h"
class Asteroids : public GameObjectPool<Asteroid, 50>
{
public:
	Asteroids(SDLGame* game,Vector2D vel, double x, double y, double width, double height);
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

