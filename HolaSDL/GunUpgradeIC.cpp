#include "GunUpgradeIC.h"
#include <sstream>
#include "InputHandler.h"
#include "Logger.h"
GunUpgradeIC::GunUpgradeIC(SDL_Keycode v)
{
	v_ = v;
}

GunUpgradeIC::~GunUpgradeIC()
{
}

void GunUpgradeIC::handleInput(Container* c, Uint32 time)
{
	if (InputHandler::getInstance()->isAnyKeyDown())
	{
		if (InputHandler::getInstance()->isKeyDown(v_))
		{
			Vector2D p = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) + Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
			Vector2D d = Vector2D(0, -1).rotate(c->getRotation());
			// p es la posición y d es la dirección de la bala
			Logger::getInstance()->log([p, d]() {
				stringstream s;
				s << "Shooting: " << p << " " << d;
				return s.str();
				});
			c->globalSend(this, msg::Shoot(msg::FighterGun, msg::Broadcast, p, d, 0)); // primera bala
			Vector2D d2 = d.rotate(-5);
			c->globalSend(this, msg::Shoot(msg::FighterGun, msg::Broadcast, p, d2, 0)); // segunda bala
			Vector2D d3 = d.rotate(5);
			c->globalSend(this, msg::Shoot(msg::FighterGun, msg::Broadcast, p, d3, 0)); // tercera bala
			
		}
	}
}
