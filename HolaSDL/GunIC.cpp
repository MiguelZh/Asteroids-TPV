#include "GunIC.h"



GunIC::GunIC(SDL_Keycode space)
{
	space_ = space;
}


GunIC::~GunIC()
{
}

void GunIC::handleInput(const SDL_Event & event, Container * c, Uint32 time)
{
	if (event.key.keysym.sym == space_) {
		Vector2D p =  c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) + Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
		Vector2D d = Vector2D(0, -1).rotate(c->getRotation());
	}

}