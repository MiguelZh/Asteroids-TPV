#pragma once
#include "Container.h"
class ThrustIC
{
protected:
	double thrust_; // betweeen 0-1
	double speedLimit_;
	SDL_Keycode up_;
public:
	ThrustIC(SDL_Keycode up,double thrust, double speedLimit);
	virtual ~ThrustIC();
	virtual void handleInput(const SDL_Event & event, Container * c, Uint32 time);
};

