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
	//pending
	int a = 10;
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
