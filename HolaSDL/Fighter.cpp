#include "Fighter.h"

Fighter::Fighter(SDLGame* game, int x, int y, int width, int height, int angle) :
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 })
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
		case SDLK_RIGHT:
			// rotate fighter to right
			//rotation_ = ((int) this->getRotation() + 5) % 360;
			rotation__.update(this, time, this->getRotation());
			velocity_ = velocity_.rotate(5);
			break;
		case SDLK_LEFT:
			// rotate fighter to left
			//rotation_ = ((int)this->getRotation() + 360 - 5) % 360;
			rotation__.update(this, time, -this->getRotation());
			velocity_ = velocity_.rotate(-5);
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
	/*
	//Movement
	position_ = position_ + velocity_;
	// when exiting from one side appear in the other
		
	if (position_.getX() >= getGame()->getWindowWidth()) {
		position_.setX(1 - width_);
	} else if (position_.getX() + width_ <= 0) {
		position_.setX(getGame()->getWindowWidth());
	}
	if (position_.getY() >= getGame()->getWindowHeight()) {
		position_.setY(1 - height_);
	} else if (position_.getY() + height_ <= 0) {
		position_.setY(getGame()->getWindowHeight());
	}*/
}

void Fighter::render(Uint32 time) {
	// where to render it
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(),
			getHeight());
	fighterImage_.render(this, 1);
}
