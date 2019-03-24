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
	virtual ~Asteroid();
	int getGenerations();
	void setGenerations(int generations);
private:
	int generations_;
};

