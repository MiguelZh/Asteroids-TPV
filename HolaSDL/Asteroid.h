#pragma once
#include"ImageGC.h"
#include"NaturalMovePC.h"
#include"ShowUpAtOppositeSidePC.h"
#include"Container.h"
#include"RotatingPC.h"
class Asteroid : public Container
{
public:
	Asteroid();
	Asteroid(SDLGame* game,double x, double y, int width, int height);
	virtual ~Asteroid();
	void update(Uint32 time);
	void render(Uint32 time);
private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};

