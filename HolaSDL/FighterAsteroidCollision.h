#pragma once
#include "PhysicsComponent.h"
class FighterAsteroidCollision : public PhysicsComponent
{
public:
	FighterAsteroidCollision();
	virtual ~FighterAsteroidCollision();
	virtual void update(Container* c, Uint32 time);
};

