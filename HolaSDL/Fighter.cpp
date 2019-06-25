#include "Fighter.h"
Fighter::Fighter(SDLGame* game) :
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 }),
	rotation_(SDLK_LEFT,SDLK_RIGHT,5,SDLK_r),
	thrust_(SDLK_UP,0.5,4.0),
	reduceSpeed_(0.995),
	normalGun_(SDLK_SPACE),
	upgradedGun_(SDLK_v)
{
	setId(msg::Fighter);
	setWidth(75);
	setHeight(75);
	setRotation(0.5);
	setActive(false);
	addC(&fighterImage_);
	addC(&naturalMove_);
	addC(&oppositeSide_);
	addC(&rotation_);
	addC(&thrust_);
	addC(&reduceSpeed_);
	addC(&normalGun_);
	//rotation_ = 90;
	//bs_ = bs;
}

Fighter::~Fighter() {

}

void Fighter::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
	case msg::GAME_START:
		globalSend(this, msg::FighterInfo(msg::Fighter, msg::Broadcast, this)); // primer this porque envias todo el fighter, no te interesa el parametro
		break;
	case msg::ROUND_START:
		setActive(true);
		setVelocity({ 0,0 });
		setPosition({ (double)getGame()->getWindowWidth() / 2, (double)getGame()->getWindowHeight() / 2 });
		break;
		case msg::ROUND_OVER:
			setActive(false);
			break;
		case msg::UPGRADE_BULLET: {
			bool activate = static_cast<const msg::UpgradeBulletInfo&>(msg).change_;
			if (activate) 
				addC(&upgradedGun_);	
			break;
		}
		case msg::GAME_OVER:
			removeC(&upgradedGun_);
			break;
	default:
		break;
	}
}

void Fighter::update(Uint32 time)
{
	globalSend(this, msg::FighterInfo(msg::Fighter, msg::Broadcast, this)); // primer this porque envias todo el fighter, no te interesa el parametro
	Container::update(time);
}
