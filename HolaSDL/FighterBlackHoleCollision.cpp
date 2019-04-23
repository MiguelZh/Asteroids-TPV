#include "FighterBlackHoleCollision.h"
#include "GameManager.h"
#include"Collisions.h"
#include "Messages_defs.h"


FighterBlackHoleCollision::FighterBlackHoleCollision()
{
}


FighterBlackHoleCollision::~FighterBlackHoleCollision()
{
}

void FighterBlackHoleCollision::update(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c);
	if (gm->getRunning())
	{
		if (fighter_ != nullptr && blackholes_ != nullptr)
		{
			bool collided = false;
			for (auto i = blackholes_->begin(); i != blackholes_->end() && !collided; i++)
			{
				if (fighter_->isActive() && (*i)->isActive() && Collisions::collidesWithRotation(fighter_, *i))
				{
					c->globalSend(this, msg::FighterBlackHoleCollisionMsg(msg::None, msg::Broadcast, fighter_, *i));
					collided = true;
				}
			}
		}
	}
}

void FighterBlackHoleCollision::receive(Container * c, const msg::Message & msg)
{
	//Container::receive(c, msg);
	switch (msg.type_)
	{
	case  msg::BLACKHOLE_INFO:
		blackholes_ = static_cast<const msg::BlackHolesInfo&>(msg).blackHoles_;
		break;
	case msg::FIGHTER_INFO:
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		break;
	}
}
