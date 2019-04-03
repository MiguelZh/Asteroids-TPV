#pragma once
#include "Container.h"
#include"Messages_defs.h"
#include"InputComponent.h"
#include "Component.h"
class GunIC : public InputComponent
{
private:
	SDL_Keycode space_;
public:
	GunIC(SDL_Keycode space);
	virtual ~GunIC();
	virtual void handleInput(Container* c, Uint32 time);
};

