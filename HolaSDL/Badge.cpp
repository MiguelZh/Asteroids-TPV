#include "Badge.h"
#include "Messages_defs.h"
Badge::Badge(SDLGame* game) :Container(game), 
badgeImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Badges), { 235, 25, 130, 130 })
{
	setId(msg::Fighter);
	addC(&badgeImage_);
}

Badge::~Badge()
{
}

void Badge::receive(const void* senderObj, const msg::Message& msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
	case msg::GAME_START:
		setActive(false);
	case msg::ROUND_START:
		setPosition({ (double)getGame()->getWindowWidth() / 2, 20 });
		setWidth(50);
		setHeight(50);
		break;
	case msg::GAME_OVER:
		setActive(false);
		break;
	case msg::UPGRADE_BULLET:
		bool activate = static_cast<const msg::UpgradeBulletInfo&>(msg).change_;
		if (activate)
			setActive(true);
		break;
	}
}
