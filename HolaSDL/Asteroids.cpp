#include"Asteroids.h"
#include"Messages_defs.h"
#include "Logger.h"
#include <sstream>


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
	// adds all components to all asteroids but they dont spawn yet
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
		for (int i = 0; i < 10; i++) {
			Asteroid *a = getUnusedObject();
			if (a != nullptr){
			a->setGenerations(3);
			a->setWidth(40);
			a->setHeight(40);
			int borde = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 4);
			Vector2D p;
			switch (borde) {
			case 0: // derecha
				p = { (double)getGame()->getWindowWidth(),(double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, (double)getGame()->getWindowHeight()) };
				a->setPosition(p);
				break;
			case 1: // arriba
				p = { (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, (double)getGame()->getWindowWidth()),0 };
				a->setPosition(p);
				break;
			case 2: // izquierda
				p = { 0,(double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, (double)getGame()->getWindowHeight()) };
				a->setPosition(p);
				break;
			case 3: // abajo
				p = { (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, (double)getGame()->getWindowWidth()),(double)getGame()->getWindowHeight() };
				a->setPosition(p);
				break;
			}
			Vector2D c = Vector2D((double)getGame()->getWindowWidth() / 2, (double)getGame()->getWindowHeight() / 2);
			Vector2D v = (c - a->getPosition()).normalize() * ((double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(1, 10) / 20.0);
			// al crear un asteroide, p es la posición y v es la velocidad del asteroide
			Logger::getInstance()->log([p, v]() {
				stringstream s;
				s << "New asteroid: " << p << " " << v;
				return s.str();
			});
			a->setVelocity(v);
			a->setActive(true);
		}
		}
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
		break;
	case msg::BULLET_ASTEROID_COLLISION:
		Asteroid* x = static_cast<const msg::BulletAsteroidCollision&>(msg).asteroid_; // asteroid destruido
 		int randomX, randomY; int generations = x->getGenerations(); int width = x->getWidth(); int height = x->getHeight();
		double velX, velY;
		x->setActive(false);
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0);
		globalSend(this, msg::AsteroidDestroyed(msg::Asteroids,msg::Broadcast, 4 - x->getGenerations()));
		if(x->getGenerations() > 1)
		{	
			for (int i = 1; i <3; i++) {
				randomX = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 2);
				randomY = getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, 2);
				switch (randomX)
				{
				case 0:
					velX = -1.5;
					break;
				case 1:
					velX = 1.5;
					break;
				}
				switch (randomY)
				{
				case 0:
					velY = -1.5;
					break;
				case 1:
					velY = 1.5;
					break;
				}				
				Asteroid *a = getUnusedObject();
				a->setGenerations(generations- 1);
				a->setWidth( width * 0.75);
				a->setHeight(height * 0.75);				
				a->setVelocity(Vector2D(x->getVelocity().getX() * velX, x->getVelocity().getY() * velY)); // probando cosas para hacer el gameplay mas divertido
				a->setRotation(x->getRotation() + i*30);
				a->setPosition(x->getPosition() + x->getVelocity() * getGame()->getServiceLocator()->getRandomGenerator()->nextInt(-1,1));
				a->setActive(true);
			}
			//x->setActive(false);
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


