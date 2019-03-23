#include "BulletsAsteroidsCollision.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Messages_defs.h"


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
			//i = asteroids 
			for (auto i = asteroids_->begin(); i != asteroids_->end() && !collided; i++)
			{
				//j = bullets
				for (auto j = bullets_->begin(); j != bullets_->end() && !collided; j++) 
				{
					if ((*j)->isActive() && (*i)->isActive() && Collisions::collidesWithRotation(*j, *i))
					{
						c->globalSend(this, msg::BulletAsteroidCollision(msg::None,msg::Broadcast,*j,*i));
						collided = true;
					}
				}
			}
		}
	}
}
