#include "Fighter.h"

Fighter::Fighter(SDLGame* game) :
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 }),
	rotation__(SDLK_LEFT,SDLK_RIGHT,5),
	thrust_(SDLK_UP,0.5,4.0),
	reduceSpeed_(0.995)
{
	setWidth(75);
	setHeight(75);
	setPosition(Vector2D(game->getWindowWidth() / 2, game->getWindowHeight() / 2));
	setRotation(0.5);
	setVelocity({ 1, 1 });
	//rotation_ = 90;
	//bs_ = bs;
}

Fighter::~Fighter() {
}

void Fighter::handleInput(Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		rotation__.handleInput(event, this, time);
		thrust_.handleInput(event, this, time);
		switch (event.key.keysym.sym) {
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
	oppositeSide_.update(this,time); //Reappearing in side screens
	reduceSpeed_.update(this, time); //Reduce speed with time
}

void Fighter::render(Uint32 time) {
	// where to render it
	SDL_Rect dest = RECT(getPosition().getX(), getPosition().getY(), getWidth(),
			getHeight());
	fighterImage_.render(this, 1);
}
