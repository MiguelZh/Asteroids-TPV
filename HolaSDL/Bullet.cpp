#include "Bullet.h"



Bullet::Bullet()
{
}

Bullet::Bullet(SDLGame * game, NaturalMovePC naturalMove, DeactivateOnBorderExit deactivate, ImageGC bulletImage):
	Container(game),
	bulletImage_(bulletImage),
	deactivate_(deactivate),
	naturalMove_(naturalMove)
{
	addC(&bulletImage_);
	addC(&deactivate_);
	addC(&naturalMove_);
}


Bullet::~Bullet()
{
}
