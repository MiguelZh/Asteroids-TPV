#include "ThrustIC.h"



ThrustIC::ThrustIC(SDL_Keycode up,double thrust, double speedLimit)
{
	up_ = up;
	thrust_ = thrust;
	speedLimit_ = speedLimit;
}


ThrustIC::~ThrustIC()
{
}

void ThrustIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	// increase velocity
	if (event.key.keysym.sym == up_) {
		c->setVelocity(c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())*thrust_));
		if (c->getVelocity().magnitude() > speedLimit_) {
			c->setVelocity(c->getVelocity().normalize()*speedLimit_);
		}
	}
}

