#include "Asteroid.h"



Asteroid::Asteroid()
{

}

Asteroid::Asteroid(SDLGame* game):
	Container(game),
	asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	rotating_(10)
{
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

void Asteroid::setValue(Vector2D vel, double x, double y, double width, double height)
{
	setWidth(width);
	setHeight(height);
	setPosition({x,y });
	setVelocity(vel);
}
