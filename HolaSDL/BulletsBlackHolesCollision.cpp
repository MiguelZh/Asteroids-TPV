#include "BulletsBlackHolesCollision.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Messages_defs.h"


BulletsBlackHolesCollision::BulletsBlackHolesCollision()
{
}


BulletsBlackHolesCollision::~BulletsBlackHolesCollision()
{
}

void BulletsBlackHolesCollision::update(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);
	if (gm->getRunning())
	{
		if (blackHoles_ != nullptr && bullets_ != nullptr)
		{
			bool collided = false;
			// doble for, el for de dentro compara todas las balas con cada asteroid
			//i = blackholes 
			for (auto i = blackHoles_->begin(); i != blackHoles_->end() && !collided; i++)
			{
				//j = bullets
				for (auto j = bullets_->begin(); j != bullets_->end() && !collided; j++)
				{
					if ((*j)->isActive() && (*i)->isActive() && Collisions::collidesWithRotation(*j, *i))
					{
						c->globalSend(this, msg::BulletBlackHoleCollision(msg::None, msg::Broadcast, *j, *i));
						collided = true;
					}
				}
			}
		}
	}
}

void BulletsBlackHolesCollision::receive(Container * c, const msg::Message & msg)
{
	//Container::receive(c, msg);
	switch (msg.type_)
	{
	case  msg::BLACKHOLE_INFO:
		blackHoles_ = static_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
		break;
	case msg::BULLETS_INFO:
		bullets_ = static_cast<const msg::BulletsInfoMsg&>(msg).bullets_;
		break;
	}
}
