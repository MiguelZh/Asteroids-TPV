#include "BlackHoles.h"



BlackHoles::BlackHoles(SDLGame* game) : GameObjectPool(game),
blackHoleImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BlackHole)),
rotating_((double)game->getServiceLocator()->getRandomGenerator()->nextInt(8 ,30))
{
	setId(msg::BlackHoles);
	setWidth(50);
	setHeight(50);
	for (BlackHole* b : getAllObjects()) {
		b->addC(&rotating_);
		b->addC(&blackHoleImage_);
		b->setWidth(getWidth());
		b->setHeight(getHeight());
		b->setVelocity({ 0,0 });
	}
}


BlackHoles::~BlackHoles()
{
}

void BlackHoles::receive(const void * senderObj, const msg::Message & msg)
{
}
