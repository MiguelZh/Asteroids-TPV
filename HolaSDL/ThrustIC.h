#pragma once
#include "InputComponent.h"
class ThrustIC : public InputComponent
{
protected:
	double thrust_; // betweeen 0-1
	double speedLimit_;
	SDL_Keycode up_;
public:
	ThrustIC(SDL_Keycode up,double thrust, double speedLimit);
	virtual ~ThrustIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};

