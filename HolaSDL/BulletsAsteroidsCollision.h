#pragma once
#include "PhysicsComponent.h"
#include "Asteroid.h"
#include "Bullet.h"
class BulletsAsteroidsCollision : public PhysicsComponent
{
private:
	const vector<Asteroid*>* asteroids_ = nullptr;
	const vector<Bullet*>* bullets_ = nullptr;
public:
	BulletsAsteroidsCollision();
	virtual ~BulletsAsteroidsCollision();
	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};

