#include "ShowUpAtOppositeSidePC.h"



ShowUpAtOppositeSidePC::ShowUpAtOppositeSidePC()
{
}


ShowUpAtOppositeSidePC::~ShowUpAtOppositeSidePC()
{
}

void ShowUpAtOppositeSidePC::update(Container * c, Uint32 time)
{
	if (c->getPosition().getX() >= c->getGame()->getWindowWidth()) {
		c->setPosition(Vector2D((1 - c->getWidth()),c->getPosition().getY()));
	}
	else if (c->getPosition().getX() + c->getWidth() <= 0) {
		c->setPosition(Vector2D((c->getGame()->getWindowWidth()), c->getPosition().getY()));
	}
	if (c->getPosition().getY() >= c->getGame()->getWindowHeight()) {
		c->setPosition(Vector2D(c->getPosition().getY(),1 - c->getHeight()));
	}
	else if (c->getPosition().getY() + c->getHeight() <= 0) {
		c->setPosition(Vector2D(c->getPosition().getX(),c->getGame()->getWindowHeight()));
	}
}
