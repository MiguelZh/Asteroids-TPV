#include "AsteroidsGame.h"
#include "Logger.h"

using namespace std;

AsteroidsGame::AsteroidsGame() :
	SDLGame("Asteroids", _WINDOW_WIDTH_, _WINDOW_HEIGHT_),
	gameManager_(this),
	demoContainer_(this),
	fighter_(this),
	asteroids_(this),
	bullets_(this)
{
	initGame();
	Logger::getInstance()->initInstance("log.txt");
}

AsteroidsGame::~AsteroidsGame() {
	closeGame();
}

void AsteroidsGame::initGame() {
	actors_.push_back(&gameManager_);
	//actors_.push_back(&demoContainer_);
	actors_.push_back(&fighter_);
	actors_.push_back(&asteroids_);
	actors_.push_back(&bullets_);
	//observadores
	addObserver(&fighter_);
	addObserver(&gameManager_);
	addObserver(&asteroids_);
	addObserver(&bullets_);
}

void AsteroidsGame::closeGame() {
}

void AsteroidsGame::start() {
	exit_ = false;

	while (!exit_) {
		Uint32 startTime = SDL_GetTicks();
		handleInput(startTime);
		update(startTime);
		render(startTime);

		Uint32 frameTime = SDL_GetTicks() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

void AsteroidsGame::stop() {
	exit_ = true;
}

void AsteroidsGame::handleInput(Uint32 time) {
	InputHandler::getInstance()->update();

	for (GameObject* o : actors_) {
		o->handleInput(time);
	}
		/*SDL_Event event;
while (SDL_PollEvent(&event)) {
	if (event.type == SDL_KEYDOWN) {

		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			exit_ = true;
			break;
		// Pressing f to toggle fullscreen.
		case SDLK_f:
			int flags = SDL_GetWindowFlags(window_);
			if (flags & SDL_WINDOW_FULLSCREEN) {
				SDL_SetWindowFullscreen(window_, 0);
			} else {
				SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN);
			}
			break;
		}
	}
	}*/
}

void AsteroidsGame::update(Uint32 time) {
	for (GameObject* o : actors_) {
		o->update(time);
	}
}

void AsteroidsGame::render(Uint32 time) {
	SDL_SetRenderDrawColor(getRenderer(), COLOR(0x00AAAAFF));
	SDL_RenderClear(getRenderer());

	for (GameObject* o : actors_) {
		o->render(time);
	}

	SDL_RenderPresent(getRenderer());
}

