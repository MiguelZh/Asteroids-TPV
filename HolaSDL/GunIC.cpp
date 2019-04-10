#include "GunIC.h"
#include "Logger.h"
#include "InputHandler.h"
#include <sstream>
GunIC::GunIC(SDL_Keycode space)
{
	space_ = space;
}


GunIC::~GunIC()
{
}

void GunIC::handleInput(Container * c, Uint32 time)
{
	if (InputHandler::getInstance()->isAnyKeyDown()) 
	{
		if (InputHandler::getInstance()->isKeyDown(space_)) 
		{
			Vector2D p = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) + Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
			Vector2D d = Vector2D(0, -1).rotate(c->getRotation());
			// p es la posición y d es la dirección de la bala
			Logger::getInstance()->log([p, d]() {
				stringstream s;
				s << "Shooting: " << p << " " << d;
				return s.str();
			});
			c->globalSend(this, msg::Shoot(msg::FighterGun, msg::Broadcast, p, d, 0));
		}
	}
}