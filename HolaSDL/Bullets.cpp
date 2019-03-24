#include "Bullets.h"
#include "Messages_defs.h"
#include "Messages_decl.h"

Bullets::Bullets(SDLGame * game):
	GameObjectPool(game),
	naturalMove_(),
	bulletImage_(getGame()->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)),
	deactivate_()
{
	setId(msg::Bullets);
	for (Bullet * b : getAllObjects()) {
		b->addC(&naturalMove_);
		b->addC(&deactivate_);
		b->addC(&bulletImage_);
	}
}


Bullets::~Bullets()
{
}

/*void Bullets::shootBullet()
{
	Bullet *b = getUnusedObject();
	if (b != nullptr) {
		b->setWidth(10);
		b->setHeight(10);
		b->setPosition({ 200, 300 });
		b->setVelocity({ 0, -1 });
		b->setActive(true);
	}
}*/

void Bullets::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);
	msg::Shoot shoot = static_cast<const msg::Shoot&>(msg);
	switch (msg.type_)
	{
	case msg::GAME_START:
		globalSend(this, msg::BulletsInfoMsg(msg::Bullets, msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START:
		setActive(true);
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
	case msg::BULLET_ASTEROID_COLLISION:
		Bullet * x = static_cast<const msg::BulletAsteroidCollision&>(msg).bullet_; // bala colisionada
		x->setActive(false);
		break;
	case msg::FIGHTER_SHOOT:
		Bullet * b = getUnusedObject();
		if (b != nullptr) {
			b->setWidth(1);
			b->setHeight(5);
			b->setPosition(shoot.pos_ - Vector2D(b->getWidth() / 2, b->getHeight()));
			b->setVelocity(shoot.dir_ * 5);
			b->setRotation(Vector2D(0, -1).angle(shoot.dir_));
			b->setActive(true);
		}
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::GunShot,0);
		break;		
	default:
		break;
	}
}

/*void Bullets::handleInput(Uint32 time, const SDL_Event & event)
{
	if (event.key.keysym.sym == SDLK_SPACE) 
	{
		shootBullet();
	}
}*/


