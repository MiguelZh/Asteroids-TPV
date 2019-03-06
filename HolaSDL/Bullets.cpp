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

void Bullets::shootBullet()
{
	Bullet *b = getUnusedObject();
	if (b != nullptr) {
		b->setWidth(10);
		b->setHeight(10);
		b->setPosition({ 200, 300 });
		b->setVelocity({ 0, -1 });
		b->setActive(true);
	}
}

void Bullets::handleInput(Uint32 time, const SDL_Event & event)
{
	if (event.key.keysym.sym == SDLK_SPACE) 
	{
		cout << "alvar gay xd";
		shootBullet();
	}
}


