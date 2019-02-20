#pragma once
#include "Container.h"
class RotationIC
{
public:
	RotationIC();
	virtual ~RotationIC();
	virtual void update(Container* c, Uint32 time, int angle);
};

