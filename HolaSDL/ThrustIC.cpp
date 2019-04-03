#include "ThrustIC.h"

#include "InputHandler.h"


ThrustIC::ThrustIC(SDL_Keycode up,double thrust, double speedLimit)
{
	up_ = up;
	thrust_ = thrust;
	speedLimit_ = speedLimit;
}


ThrustIC::~ThrustIC()
{
}

void ThrustIC::handleInput(Container * c, Uint32 time)
{
	// increase velocity
	if (InputHandler::getInstance()->isAnyKeyDown()) {

		if (InputHandler::getInstance()->isKeyDown(up_))
		{
			c->setVelocity(c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())*thrust_));
			if (c->getVelocity().magnitude() > speedLimit_) 
			{
				c->setVelocity(c->getVelocity().normalize()*speedLimit_);
			}
		}
	}
}

