#include "Bullets.h"



Bullets::Bullets(SDLGame * game):
	GameObjectPool(game),
	naturalMove_(),
	bulletImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)),
	deactivate_()
{
	for (Bullet * b : getAllObjects()) {
		b->addC(&naturalMove_);
		b->addC(&deactivate_);
		b->addC(&bulletImage_);
	}
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

