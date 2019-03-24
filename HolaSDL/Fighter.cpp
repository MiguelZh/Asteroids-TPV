#include "Fighter.h"

Fighter::Fighter(SDLGame* game) :
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 }),
	rotation_(SDLK_LEFT,SDLK_RIGHT,5),
	thrust_(SDLK_UP,0.5,4.0),
	reduceSpeed_(0.995),
	normalGun_(SDLK_SPACE)
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
		setPosition({ getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2 });
		break;
		case msg::ROUND_OVER:
			setActive(false);
			break;
	default:
		break;
	}
}
