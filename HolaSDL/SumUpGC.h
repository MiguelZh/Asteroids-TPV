#pragma once
#include "GraphicsComponent.h"
class SumUpGC : public GraphicsComponent
{

public:
	SumUpGC();
	~SumUpGC();
	virtual void render(Container* c, Uint32 time);
};

