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
	double xCoord= 0, yCoord = 0;
	switch (msg.type_)
	{
	case msg::GAME_START:
		globalSend(this, msg::BlackHolesInfo(msg::BlackHoles, msg::Broadcast, &getAllObjects()));
		nBlackHoles = 1;
		break;
	case msg::ROUND_START:
		setActive(true);
		nBlackHoles *= 2;
		for (int i = 0; i < nBlackHoles; i++) {
			BlackHole* b = getUnusedObject();
			do {
				xCoord = (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth());
			} while (xCoord < (getGame()->getWindowWidth()/2)+100 && xCoord > (getGame()->getWindowWidth() / 2) - 100);
			do {
				yCoord = (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
			} while (yCoord < (getGame()->getWindowHeight() / 2) + 100 && yCoord >(getGame()->getWindowHeight() / 2) - 100);
			Vector2D pos = {xCoord, yCoord};
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
		fighter_ = static_cast<const msg::FighterInfo&>(msg).fighter_;

		do {
			xCoord = (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowWidth());
		} while (xCoord < fighter_->getPosition().getX() + 100 && xCoord < fighter_->getPosition().getX() - 100);
		do {
			yCoord = (double)getGame()->getServiceLocator()->getRandomGenerator()->nextInt(0, getGame()->getWindowHeight());
		} while (yCoord < fighter_->getPosition().getY() + 100 && yCoord < fighter_->getPosition().getY() - 100);

		Vector2D randomPos = {xCoord, yCoord};
		x->setPosition(randomPos);
		break;
	}

}
