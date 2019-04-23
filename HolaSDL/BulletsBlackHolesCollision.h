#pragma once
#include "PhysicsComponent.h"
#include "BlackHole.h"
#include "Bullet.h"
class BulletsBlackHolesCollision : public PhysicsComponent
{
private:
	const vector<BlackHole*>* blackHoles_ = nullptr;
	const vector<Bullet*>* bullets_ = nullptr;
public:
	BulletsBlackHolesCollision();
	virtual ~BulletsBlackHolesCollision();
	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};

