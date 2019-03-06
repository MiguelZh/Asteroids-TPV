#pragma once
#include "PhysicsComponent.h"
class BulletsAsteroidsCollision : public PhysicsComponent
{
public:
	BulletsAsteroidsCollision();
	virtual ~BulletsAsteroidsCollision();
	virtual void update(Container* c, Uint32 time);
};

