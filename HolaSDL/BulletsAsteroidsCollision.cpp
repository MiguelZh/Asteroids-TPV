#include "BulletsAsteroidsCollision.h"
#include "GameManager.h"


BulletsAsteroidsCollision::BulletsAsteroidsCollision()
{
}


BulletsAsteroidsCollision::~BulletsAsteroidsCollision()
{
}

void BulletsAsteroidsCollision::update(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);
	if (gm->getRunning()) 
	{
		if (asteroids_ != nullptr && bullets_ != nullptr) 
		{
			bool collided = false;
			// doble for, el for de dentro compara todas las balas con cada asteroid
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
