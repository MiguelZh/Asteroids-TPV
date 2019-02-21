#include "RotatingPC.h"



RotatingPC::RotatingPC()
{
}

RotatingPC::RotatingPC(int angle)
{
	angle_ = angle;
}


RotatingPC::~RotatingPC()
{
}

void RotatingPC::update(Container * c, Uint32 time)
{
	c->setRotation(c->getRotation() + angle_);
}
