#include "Asteroids.h"





Asteroids::Asteroids(SDLGame* game,Vector2D vel, double x, double y, double width, double height):
	GameObjectPool(game),
	rotating_(10)
{
	for (Asteroid * a : getAllObjects()) {
		a->addOC(&(ImageGC) asteroidImage_);
		a->addOC(&(NaturalMovePC) naturalMove_);
		a->addOC(&(RotatingPC)rotating_);
		a->addOC(&(ShowUpAtOppositeSidePC) showUpAtOppositeSide_);
		a->setValue(vel,x, y, width, height);
		a->setActive(true);
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
