#pragma once
#include "PhysicsComponent.h"
class RotatingPC : public PhysicsComponent
{
	int angle_;
public:
	RotatingPC();
	RotatingPC(int angle);
	virtual ~RotatingPC();
	virtual void update(Container* c, Uint32 time);
};

