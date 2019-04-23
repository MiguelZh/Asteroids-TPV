#include "BlackHoles.h"
#include"Messages_defs.h"
#include "Logger.h"
#include <sstream>
#include "Bullet.h"
#include "Asteroid.h"
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
	}
}


BlackHoles::~BlackHoles()
{
}

void BlackHoles::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);
	switch (msg.type_)
	{
	case msg::GAME_START:
		globalSend(this, msg::BlackHolesInfo(msg::BlackHoles, msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START:
		setActive(true);
		for (int i = 0; i < 5; i++) {
			BlackHole* b = getUnusedObject();
			Vector2D pos = { (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth()),(double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0 ,getGame()->getWindowHeight()) };
			b->setPosition(pos);
			b->setActive(true);
		}
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
		break;
	case msg::ASTEROID_BLACKHOLE_COLLISION:
		Asteroid* x = static_cast<const msg::AsteroidBlackHoleCollision&>(msg).asteroid_; // asteroid destruido
		Vector2D randomPos = { (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth()),(double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0 ,getGame()->getWindowHeight()) };
		x->setPosition(randomPos);
		break;
	}

}
