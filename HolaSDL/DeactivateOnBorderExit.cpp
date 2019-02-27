#include "DeactivateOnBorderExit.h"



DeactivateOnBorderExit::DeactivateOnBorderExit()
{
}


DeactivateOnBorderExit::~DeactivateOnBorderExit()
{
}

void DeactivateOnBorderExit::update(Container * c, Uint32 time)
{
	bool outOfMap = false;
	if (c->getPosition().getX() >= c->getGame()->getWindowWidth()) {
		outOfMap = true;
	}
	else if (c->getPosition().getX() + c->getWidth() <= 0) {
		outOfMap = true;
	}
	else if (c->getPosition().getY() >= c->getGame()->getWindowHeight()) {
		outOfMap = true;
	}
	else if (c->getPosition().getY() + c->getHeight() <= 0) {
		outOfMap = true;
	}
	if (outOfMap) c->setActive(false);
}
