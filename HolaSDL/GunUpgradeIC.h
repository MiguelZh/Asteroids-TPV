#pragma once
#include "Container.h"
#include"Messages_defs.h"
#include"InputComponent.h"
#include "Component.h"
class GunUpgradeIC : public InputComponent
{
private:
	SDL_Keycode v_;
public:
	GunUpgradeIC(SDL_Keycode v);
	virtual ~GunUpgradeIC();
	virtual void handleInput(Container* c, Uint32 time);
};

