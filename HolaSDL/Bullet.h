#pragma once
#include"NaturalMovePC.h"
#include"DeactivateOnBorderExit.h"
#include "ImageGC.h"
#include "Container.h"
class Bullet : public Container
{
public:
	Bullet();
	virtual ~Bullet();
	void setComponent(NaturalMovePC naturalMove, DeactivateOnBorderExit deactivate, ImageGC bulletImage);
private:
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;
};

