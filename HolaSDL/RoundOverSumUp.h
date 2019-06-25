#pragma once
#include "GraphicsComponent.h"
#include "Container.h"
#include "SumUpGC.h"
class RoundOverSumUp : public Container
{
private:
	int bullets_;
	int asteroids_;
	bool running_;
	SumUpGC sumUpGC;
public:
	RoundOverSumUp(SDLGame* game);
	~RoundOverSumUp();
	virtual void receive(const void* senderObj, const msg::Message& msg);
	int getBullets();
	int getAsteroids();
	bool getRunning();
};

