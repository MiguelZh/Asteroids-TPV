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

void Asteroid::setComponents(Vector2D vel, Vector2D pos, double width, double height, ImageGC asteroidImage, NaturalMovePC naturalMove, RotatingPC rotating, ShowUpAtOppositeSidePC showUpAtOppositeSide)
{
	setWidth(width);
	setHeight(height);
	setPosition(pos);
	setVelocity(vel);
	asteroidImage_ = asteroidImage;
	naturalMove_ = naturalMove;
	rotating_ = rotating;
	showUpAtOppositeSide_ = showUpAtOppositeSide;
}
