#include "RoundOverSumUp.h"
#include "GameManager.h"
#include "Messages_defs.h"
RoundOverSumUp::RoundOverSumUp(SDLGame* game): Container(game), sumUpGC()
{
	asteroids_ = 0;
	bullets_ = 0;
	running_ = false;
	addC(&sumUpGC);
}

RoundOverSumUp::~RoundOverSumUp()
{
}



void RoundOverSumUp::receive(const void* senderObj, const msg::Message& msg)
{
	Container::receive(senderObj, msg);
	switch (msg.type_) {
	case  msg::GAME_START:
	case msg::ROUND_START:
		asteroids_ = 0;
		bullets_ = 0;
		running_ = true;
		break;
	case msg::ROUND_OVER:
		running_ = false;
	case msg::ASTEROID_DESTROYED:
		asteroids_++;
		break;
	case msg::FIGHTER_SHOOT:
		bullets_++;
		break;
	default:
		break;
	}

}

int RoundOverSumUp::getBullets()
{
	return bullets_;
}

int RoundOverSumUp::getAsteroids()
{
	return asteroids_;
}

bool RoundOverSumUp::getRunning()
{
	return running_;
}
