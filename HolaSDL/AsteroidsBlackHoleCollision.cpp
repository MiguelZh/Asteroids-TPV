#include "AsteroidsBlackHoleCollision.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Messages_defs.h"


AsteroidsBlackHoleCollision::AsteroidsBlackHoleCollision()
{
}


AsteroidsBlackHoleCollision::~AsteroidsBlackHoleCollision()
{
}

void AsteroidsBlackHoleCollision::update(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);
	if (gm->getRunning())
	{
		if (asteroids_ != nullptr && blackHoles_ != nullptr)
		{
			bool collided = false;
			// doble for, el for de dentro compara todas las balas con cada asteroid
			//i = asteroids 
			for (auto i = asteroids_->begin(); i != asteroids_->end() && !collided; i++)
			{
				//j = bullets
				for (auto j = blackHoles_->begin(); j != blackHoles_->end() && !collided; j++)
				{
					if ((*j)->isActive() && (*i)->isActive() && Collisions::collidesWithRotation(*j, *i))
					{
						c->globalSend(this, msg::AsteroidBlackHoleCollision(msg::None, msg::Broadcast, *j, *i));
						collided = true;
					}
				}
			}
		}
	}
}

void AsteroidsBlackHoleCollision::receive(Container * c, const msg::Message & msg)
{
	//Container::receive(c, msg);
	switch (msg.type_)
	{
	case  msg::ASTEROIDS_INFO:
		asteroids_ = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		break;
	case msg::BLACKHOLE_INFO:
		blackHoles_ = static_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
		break;
	}
}
