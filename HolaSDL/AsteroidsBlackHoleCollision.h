#pragma once
#include "PhysicsComponent.h"
#include"Asteroid.h"
#include "BlackHole.h"
class AsteroidsBlackHoleCollision : public PhysicsComponent
{
	const vector<Asteroid*>* asteroids_ = nullptr;
	const vector<BlackHole*>* blackHoles_ = nullptr;
public:
	AsteroidsBlackHoleCollision();
	virtual ~AsteroidsBlackHoleCollision();
	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};

