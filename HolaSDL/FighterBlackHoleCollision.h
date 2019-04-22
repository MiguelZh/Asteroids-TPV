#pragma once
#include "PhysicsComponent.h"
#include "BlackHole.h"
class FighterBlackHoleCollision : public PhysicsComponent 
{
private:
	GameObject* fighter_ = nullptr;
	const vector<BlackHole*>* blackholes_ = nullptr;
public:
	FighterBlackHoleCollision();
	virtual ~FighterBlackHoleCollision();
	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);
};

