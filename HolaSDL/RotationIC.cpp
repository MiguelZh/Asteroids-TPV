#include "RotationIC.h"

#include "InputHandler.h"


RotationIC::RotationIC(SDL_Keycode left, SDL_Keycode right, int angle)
{
	left_ = left;
	right_ = right;
	angle_ = angle;
}


RotationIC::~RotationIC()
{
}

void RotationIC::handleInput(Container * c, Uint32 time)
{
	if (InputHandler::getInstance()->isAnyKeyDown()) {

		// rotate fighter to left
		if (InputHandler::getInstance()->isKeyDown(right_)) 
		{
			c->setRotation((int)(c->getRotation() + angle_) % 360);
			c->setVelocity(c->getVelocity().rotate(angle_));
		}
		// rotate fighter to right
		if (InputHandler::getInstance()->isKeyDown(left_))
		{
			c->setRotation((int)(c->getRotation() + 360 - angle_) % 360);
			c->setVelocity(c->getVelocity().rotate(-angle_));
		}
	}
	
}


