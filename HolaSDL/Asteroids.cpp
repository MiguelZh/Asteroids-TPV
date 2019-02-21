#include "Asteroids.h"





Asteroids::Asteroids(SDLGame* game,double x, double y, int width, int height):
	GameObjectPool(game),
	rotating_(10)
{
	for (Asteroid * a : getAllObjects()) {
		a->addOC(&(ImageGC) asteroidImage_);
		a->addOC(&(NaturalMovePC) naturalMove_);
		a->addOC(&(RotatingPC)rotating_);
		a->addOC(&(ShowUpAtOppositeSidePC) showUpAtOppositeSide_);
		
	}
}


Asteroids::~Asteroids()
{
}

void Asteroids::update(Uint32 time)
{
	for (Asteroid * a : getAllObjects()) {
		if (a->isActive()) {
			a->update(time);
		}
	}
}

void Asteroids::render(Uint32 time)
{
	for (Asteroid * a : getAllObjects()) {
		if (a->isActive()) {
			a->render(time);
		}
	}
}
