#pragma once
#include "GraphicsComponent.h"

class ScoreViewerGC : public GraphicsComponent
{
public:
	ScoreViewerGC();
	virtual ~ScoreViewerGC();
	virtual void render(Container* c, Uint32 time);
};

