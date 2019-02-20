#ifndef _AA
#define _AA

#include "GameObject.h"
#include "Container.h"
#include "DemoGC.h"
#include "DemoIC.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "BounceOnBorderPC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "RotationIC.h"
#include "ThrustIC.h"

class Fighter : public Container {
public:
	Fighter(SDLGame* game,int x, int y , int width, int height, int angle);
	virtual ~Fighter();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
private:
	ImageGC fighterImage_;	
	NaturalMovePC naturalMove_;
	ShowUpAtOppositeSidePC oppositeSide_;
	RotationIC rotation__;
	ThrustIC thrust_;
	/*
	ReduceSpeedPC reduceSpeed_;
	GunIC normalGun_;*/
	//BulletsShooter* bs_;
};

#endif _AA
