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
	Asteroid(SDLGame* game);
	virtual ~Asteroid();
	void update(Uint32 time);
	void render(Uint32 time);
	void setComponents(Vector2D vel , Vector2D pos, double width, double height, ImageGC asteroidImage_,NaturalMovePC naturalMove, RotatingPC rotating ,ShowUpAtOppositeSidePC showUpAtOppositeSide);
private:
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;

};

