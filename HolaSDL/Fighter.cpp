#include "Fighter.h"

Fighter::Fighter(SDLGame* game) :
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 }),
	rotation_(SDLK_LEFT,SDLK_RIGHT,5),
	thrust_(SDLK_UP,0.5,4.0),
	reduceSpeed_(0.995),
	normalGun_(SDLK_SPACE)
{
	setWidth(75);
	setHeight(75);
	setPosition(Vector2D(game->getWindowWidth() / 2, game->getWindowHeight() / 2));
	setRotation(0.5);
	setVelocity({ 1, 1 });
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
