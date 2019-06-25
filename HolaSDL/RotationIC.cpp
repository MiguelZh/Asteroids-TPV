#include "RotationIC.h"

#include "InputHandler.h"


RotationIC::RotationIC(SDL_Keycode left, SDL_Keycode right, int angle, SDL_Keycode r)
{
	left_ = left;
	right_ = right;
	r_ = r;
	angle_ = angle;
	rotating = false;
	sumaRotation = 0;
}


RotationIC::~RotationIC()
{
}

void RotationIC::handleInput(Container * c, Uint32 time)
{
	if (rotating && sumaRotation < 180) {
		c->setRotation(c->getRotation() + 2);
		sumaRotation += 2;
	}
	if (!rotating)
		sumaRotation = 0;
	if (InputHandler::getInstance()->isAnyKeyDown()) {

		// rotate fighter to left
		if (InputHandler::getInstance()->isKeyDown(right_)) 
		{
			c->setRotation((int)(c->getRotation() + angle_) % 360);
			c->setVelocity(c->getVelocity().rotate(angle_));			
			rotating = false;
		}
		// rotate fighter to right
		if (InputHandler::getInstance()->isKeyDown(left_))
		{
			c->setRotation((int)(c->getRotation() + 360 - angle_) % 360);
			c->setVelocity(c->getVelocity().rotate(-angle_));
			rotating = false;
		}
		if (InputHandler::getInstance()->isKeyDown(r_)) {
			rotating = true;
			sumaRotation = 0;
		}
	}
	
}



