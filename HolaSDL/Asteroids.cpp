#include"Asteroids.h"





Asteroids::Asteroids(SDLGame* game) :
	GameObjectPool(game),
	rotating_((double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, 10)),
	asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	naturalMove_(),
	showUpAtOppositeSide_()
{
/*	for (Asteroid *a :getAllObjects()) {
		a->setActive(true);
		Vector2D vel = { (double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5) };
		setVelocity(vel);
		Vector2D pos = { (double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowWidth()),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowHeight()) };
		setPosition(pos);
		a->setComponents(getVelocity(), getPosition(), getWidth(), getHeight(), asteroidImage_, naturalMove_, rotating_, showUpAtOppositeSide_);
	}*/
	setWidth(20);
	setHeight(20);

	for (Asteroid *a : getAllObjects()) {
		a->addC(&rotating_);
		a->addC(&asteroidImage_);
		a->addC(&naturalMove_);
		a->addC(&showUpAtOppositeSide_);
		Vector2D vel = { (double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(1, 5) };
		a->setVelocity(vel);
		Vector2D pos = { (double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowWidth()),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowHeight()) };
		a->setPosition(pos);
		a->setWidth(getWidth());
		a->setHeight(getHeight());
		a->setActive(true);
	}
}
Asteroids::~Asteroids()
{
}

