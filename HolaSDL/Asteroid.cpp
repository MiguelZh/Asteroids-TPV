#include "Asteroid.h"



Asteroid::Asteroid()
{

}

Asteroid::Asteroid(SDLGame* game, double x, double y, int width, int height):
	Container(game),
	asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	rotating_(10)
{
	setWidth(width);
	setHeight(height);
	setPosition({ (double)x,(double)y });
	setVelocity({ 1, 1 });
}


Asteroid::~Asteroid()
{
}

void Asteroid::update(Uint32 time)
{
	naturalMove_.update(this, time);
	rotating_.update(this, time);
	showUpAtOppositeSide_.update(this, time);
}

void Asteroid::render(Uint32 time)
{
	// where to render it
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(),
		getHeight());
	asteroidImage_.render(this, time);
}
