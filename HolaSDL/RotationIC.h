#pragma once
#include "Container.h"
class RotationIC
{
private:
	SDL_Keycode left_;
	SDL_Keycode right_;
	int angle_;
public:
	RotationIC(SDL_Keycode left, SDL_Keycode right, int angle);
	virtual ~RotationIC();
	virtual void handleInput(const SDL_Event & event, Container *c, Uint32 time);
};

