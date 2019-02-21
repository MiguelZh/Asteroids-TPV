#include "Asteroids.h"





Asteroids::Asteroids(SDLGame* game):
	GameObjectPool(game),
	rotating_(8),
	asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	naturalMove_(),
	showUpAtOppositeSide_()
{
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
