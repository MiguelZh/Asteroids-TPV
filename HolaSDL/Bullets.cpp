#include "Bullets.h"



Bullets::Bullets(SDLGame * game):
	GameObjectPool(game),
	naturalMove_(),
	bulletImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)),
	deactivate_()
{
	setWidth(20);
	setHeight(20);
	asignComponent(naturalMove_, deactivate_, bulletImage_);
}


Bullets::~Bullets()
{
}

void Bullets::update(Uint32 time)
{
	for (Bullet * a : getAllObjects()) {
		if (a->isActive()) {
			a->update(time);
		}
	}
}

void Bullets::render(Uint32 time)
{
	for (Bullet * a : getAllObjects()) {
		if (a->isActive()) {
			a->update(time);
		}
	}
}

void Bullets::asignComponent(NaturalMovePC naturalMove, DeactivateOnBorderExit deactivate, ImageGC bulletImage)
{
	for (Bullet *b : getAllObjects()) {
		b->setComponent(naturalMove, deactivate, bulletImage);
	}
}
