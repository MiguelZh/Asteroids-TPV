#include "FighterAsteroidCollision.h"
#include "GameManager.h"
#include"Collisions.h"
#include "Messages_defs.h"

FighterAsteroidCollision::FighterAsteroidCollision()
{
}


FighterAsteroidCollision::~FighterAsteroidCollision()
{
}

void FighterAsteroidCollision::update(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);
	if (gm->getRunning()) 
	{
		if (fighter_ != nullptr && asteroids_ != nullptr)
		{
			bool collided = false;
			for (auto i = asteroids_->begin(); i != asteroids_->end() && !collided; i++)
			{
				if (fighter_->isActive() && (*i)->isActive() && Collisions::collidesWithRotation(fighter_, *i))
				{
					c->globalSend(this, msg::FighterAsteroidCollisionMsg(msg::None, msg::Broadcast, fighter_, *i));
					collided = true;
				}
			}
		}
	}
}
