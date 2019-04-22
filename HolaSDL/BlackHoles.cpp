#include "BlackHoles.h"



BlackHoles::BlackHoles(SDLGame* game) : GameObjectPool(game),
blackHoleImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::BlackHole)),
rotating_((double)game->getServiceLocator()->getRandomGenerator()->nextInt(8 ,20))
{
	setId(msg::BlackHoles);
	setWidth(50);
	setHeight(50);
	// creates but they dont spawn
	for (BlackHole* b : getAllObjects()) {
		b->addC(&rotating_);
		b->addC(&blackHoleImage_);
		b->setWidth(getWidth());
		b->setHeight(getHeight());
		b->setVelocity({ 0,0 });
		//TODO : make blackholes not spawn in the middle
		b->setPosition({ (double)game->getServiceLocator()->getRandomGenerator()->nextInt(0, game->getWindowWidth()),(double)game->getServiceLocator()->getRandomGenerator()->nextInt(0 ,game->getWindowHeight()) });
	}
}


BlackHoles::~BlackHoles()
{
}

void BlackHoles::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);
}
