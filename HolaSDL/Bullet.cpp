#include "Bullet.h"



Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::setComponent(NaturalMovePC naturalMove, DeactivateOnBorderExit deactivate, ImageGC bulletImage)
{
	naturalMove_ = naturalMove;
	deactivate_ = deactivate;
	bulletImage_ = bulletImage;
}
