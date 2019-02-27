#pragma once
#include"NaturalMovePC.h"
#include"DeactivateOnBorderExit.h"
#include "ImageGC.h"
#include "Container.h"
class Bullet : public Container
{
public:
	Bullet();
	Bullet(SDLGame * game, NaturalMovePC naturalMove, DeactivateOnBorderExit deactivate, ImageGC bulletImage);
	virtual ~Bullet();
private:
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;
};

