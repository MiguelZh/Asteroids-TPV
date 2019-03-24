#include"Asteroids.h"
#include"Messages_defs.h"



Asteroids::Asteroids(SDLGame* game) :
	GameObjectPool(game),
	rotating_((double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, 10)),
	asteroidImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	naturalMove_(),
	showUpAtOppositeSide_()
{
	setId(msg::Asteroids);
	setWidth(20);
	setHeight(20);
	// adds all components to all asteroids viky guapa but they dont spawn yet
	for (Asteroid *a : getAllObjects()) {
		a->addC(&rotating_);
		a->addC(&asteroidImage_);
		a->addC(&naturalMove_);
		a->addC(&showUpAtOppositeSide_);		
		a->setWidth(getWidth());
		a->setHeight(getHeight());	
		a->setVelocity({ 0,0 });
	}
}
Asteroids::~Asteroids()
{
}

void Asteroids::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);
	switch (msg.type_)
	{
	case msg::GAME_START:
		globalSend(this, msg::AsteroidsInfo(msg::Asteroids, msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START:
		setActive(true);
		for (int i = 0; i < 10; i++) {
			Asteroid *a = getUnusedObject();
			int borde = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);
			switch (borde) {
			case 0: // derecha
				a->setPosition({ getGame()->getWindowWidth(),getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight()) });
				break;
			case 1: // arriba
				a->setPosition({ getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth()),0 });
				break;
			case 2: // izquierda
				a->setPosition({ 0,getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight()) });
				break;
			case 3: // abajo
				a->setPosition({ getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth()),getGame()->getWindowHeight() });
				break;
			}
			Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
			Vector2D v = (c - a->getPosition()).normalize() * (getGame()->getServiceLocator()->getRandomGenerator()->nextInt(1, 10) / 20.0);
			a->setVelocity(v);
			a->setActive(true);
		}
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
	case msg::BULLET_ASTEROID_COLLISION:
		Asteroid* x = static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_; // asteroid destruido
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0);
		x->setActive(false);
		globalSend(this, msg::AsteroidDestroyed(msg::Asteroids,msg::Broadcast, 4 - x->getGenerations()));
		if(x->getGenerations() > 1)
		{	
			for (int i = 0; i < 2; i++) {
				Asteroid *a = getUnusedObject();
				a->setGenerations(x->getGenerations()-1);
				a->setPosition(x->getPosition * 0.75);
				a->setVelocity(x->getVelocity() * 1.1);
				a->setRotation(x->getRotation() * 30);
				a->setPosition(x->getPosition() + x->getVelocity() * getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-1,1));
			}
		}
		else if (x->getGenerations() <= 1) {
			bool moreAsteroids = false;
			for (Asteroid * a : getAllObjects()) {
				if (a->getGenerations > 1) {
					moreAsteroids = true;
					return;
				}
			}
			if (!moreAsteroids) {
				globalSend(this,msg::Message(msg::NO_MORE_ASTEROIDS,msg::Asteroids,msg::Broadcast));
			}
		}
		break;
	}
}

