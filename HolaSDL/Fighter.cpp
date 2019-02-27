#include "Fighter.h"

Fighter::Fighter(SDLGame* game) :
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 }),
	rotation__(SDLK_LEFT,SDLK_RIGHT,5),
	thrust_(SDLK_UP,0.5,4.0),
	reduceSpeed_(0.995),
	normalGun_(SDLK_SPACE)
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
		normalGun_.handleInput(this, time, event);
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
