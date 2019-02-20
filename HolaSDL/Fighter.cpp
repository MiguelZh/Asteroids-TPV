#include "Fighter.h"

Fighter::Fighter(SDLGame* game, int x, int y, int width, int height, int angle) :
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 }),
	rotation__(SDLK_LEFT,SDLK_RIGHT,angle)
{
	setWidth(width);
	setHeight(height);
	setPosition({ (double)x,(double)y });
	setRotation(angle);
	setVelocity({ 2, 0 });
	//rotation_ = 90;
	//bs_ = bs;
}

Fighter::~Fighter() {
}

void Fighter::handleInput(Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		rotation__.handleInput(event, this, time);
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			// increase velocity
			if (velocity_.magnitude() < 3) {
				velocity_ = velocity_ * 1.1;
			}
			break;
		case SDLK_DOWN:
			// decrease velocity
			velocity_ = velocity_ * 0.9;
			break;
		case SDLK_SPACE: {
			// add a bullet
			/*Vector2D bulletPosition = position_
					+ Vector2D(width_ / 2, height_ / 2)
					+ Vector2D(0, -1).rotate(rotation_)*(height_/2+10);
			Vector2D bulletVelocity = velocity_
					+ Vector2D(0, -1).rotate(rotation_).normalize() * 3;
			//bs_->addBullet(bulletPosition, bulletVelocity); */
			break;
		}
		default:
			break;
		}
	}
}

void Fighter::update(Uint32 time) {
	naturalMove_.update(this, time); //Movement 
	oppositeSide_.update(this,time); // Reappearing in side screens
}

void Fighter::render(Uint32 time) {
	// where to render it
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(),
			getHeight());
	fighterImage_.render(this, 1);
}
