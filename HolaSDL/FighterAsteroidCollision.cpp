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

void FighterAsteroidCollision::receive(Container * c, const msg::Message & msg)
{
	//Container::receive(c, msg);
	switch (msg.type_)
	{
	case  msg::ASTEROIDS_INFO:
		asteroids_ = static_cast<const msg::AsteroidsInfo&>(msg).asteroids_;
		break;
	case msg::FIGHTER_INFO:
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;
		break;
	}
}
