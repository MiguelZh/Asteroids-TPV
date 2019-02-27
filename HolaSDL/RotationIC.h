#pragma once
#include "InputComponent.h"
class RotationIC : public InputComponent
{
private:
	SDL_Keycode left_;
	SDL_Keycode right_;
	int angle_;
public:
	RotationIC(SDL_Keycode left, SDL_Keycode right, int angle);
	virtual ~RotationIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};

