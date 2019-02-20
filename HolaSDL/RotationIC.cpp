#include "RotationIC.h"



RotationIC::RotationIC()
{
}


RotationIC::~RotationIC()
{
}
void RotationIC::update(Container * c, Uint32 time, int angle)
{
	c->setRotation(c->getRotation() + angle);
}

