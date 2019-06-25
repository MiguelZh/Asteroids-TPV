#pragma once
#include "InputComponent.h"
class RotationIC : public InputComponent
{
private:
	SDL_Keycode left_;
	SDL_Keycode right_;
	SDL_Keycode r_;
	int angle_;
	bool rotating;
	int sumaRotation;
public:
	RotationIC(SDL_Keycode left, SDL_Keycode right, int angle, SDL_Keycode r);
	virtual ~RotationIC();
	virtual void handleInput(Container* c, Uint32 time);
};

