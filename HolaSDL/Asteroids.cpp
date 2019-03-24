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
	setWidth(40);
	setHeight(40);
	// adds all components to all asteroids viky guapa but they dont spawn yet
	for (Asteroid *a : getAllObjects()) {
		a->addC(&rotating_);
		a->addC(&asteroidImage_);
		a->addC(&naturalMove_);
		a->addC(&showUpAtOppositeSide_);		
		a->setWidth(getWidth());
		a->setHeight(getHeight());	
		a->setVelocity({ 0,0 });
		a->setGenerations(3);
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
		for (int i = 0; i < 2; i++) {
			Asteroid *a = getUnusedObject();
			a->setGenerations(3);
			a->setWidth(40);
			a->setHeight(40);
			int borde = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);
			switch (borde) {
			case 0: // derecha
				a->setPosition({(double)getGame()->getWindowWidth(),(double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, (double)getGame()->getWindowHeight()) });
				break;
			case 1: // arriba
				a->setPosition({ (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, (double)getGame()->getWindowWidth()),0 });
				break;
			case 2: // izquierda
				a->setPosition({ 0,(double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, (double)getGame()->getWindowHeight()) });
				break;
			case 3: // abajo
				a->setPosition({ (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, (double)getGame()->getWindowWidth()),(double)getGame()->getWindowHeight() });
				break;
			}
			Vector2D c = Vector2D((double)getGame()->getWindowWidth() / 2, (double)getGame()->getWindowHeight() / 2);
			Vector2D v = (c - a->getPosition()).normalize() * ((double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(1, 10) / 20.0);
			a->setVelocity(v);
			a->setActive(true);
		}
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
		break;
	case msg::BULLET_ASTEROID_COLLISION:
		Asteroid* x = static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_; // asteroid destruido
		x->setActive(false);
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0);
		globalSend(this, msg::AsteroidDestroyed(msg::Asteroids,msg::Broadcast, 4 - x->getGenerations()));
		if(x->getGenerations() > 1)
		{	
			for (int i = 1; i <3; i++) {
				Asteroid *a = getUnusedObject();
				a->setGenerations(x->getGenerations()-1);
				//a->setWidth(x->getWidth() * 0.75);
				//a->setHeight(x->getHeight() * 0.75);
				a->scale(0.75);
				a->setVelocity(x->getVelocity() * (1.1 * i)); // probando cosas para hacer el gameplay mas divertido
				a->setRotation(x->getRotation() + i*30);
				a->setPosition(x->getPosition() + x->getVelocity() * getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-1,1));
				a->setActive(true);
			}
		}
		else if (x->getGenerations() <= 1) {
			bool moreAsteroids = false;
  			for (Asteroid * a : getAllObjects()) {
				if (a->getGenerations() > 1 && a->isActive()) {
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


