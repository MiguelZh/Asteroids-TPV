#include "Asteroids.h"





Asteroids::Asteroids(SDLGame* game) :
	GameObjectPool(game),
	rotating_(8),
	asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	naturalMove_(),
	showUpAtOppositeSide_()
{

	setWidth(20);
	setHeight(20);
	Vector2D vel = {(double) game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5) };
	setVelocity(vel);
	Vector2D pos ={ (double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowWidth()),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowHeight())};
	setPosition(pos);
	vector<Asteroid*> asteroids = getAllObjects();

	Asteroid *a = getUnusedObject();
	a->setActive(true);
	a->setComponents(getVelocity(), getPosition(), getWidth(), getHeight(), asteroidImage_, naturalMove_, rotating_, showUpAtOppositeSide_);		
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
