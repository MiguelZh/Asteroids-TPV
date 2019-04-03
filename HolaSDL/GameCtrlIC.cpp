#include "GameCtrlIC.h"

#include "InputHandler.h"
#include "Messages_defs.h"
#include "GameManager.h"

GameCtrlIC::GameCtrlIC()
{
}

GameCtrlIC::~GameCtrlIC()
{
}

void GameCtrlIC::handleInput(Container* c, Uint32 time)
{
	GameManager * gm = static_cast<GameManager*>(c);

	// if any key pressed while not running, we choose a random velocity of the ball
	if (InputHandler::getInstance()->isAnyKeyDown()) {

		if (InputHandler::getInstance()->isKeyDown(SDLK_ESCAPE)) {
			gm->getGame()->stop(); // game will stop in the next iteration
		}
		else if (!gm->getRunning()) 
		{
			if (gm->getGameOver()) {
				c->globalSend(this, msg::Message(msg::GAME_START, c->getId(), msg::Broadcast));
			}
			c->globalSend(this, msg::Message(msg::ROUND_START, c->getId(), msg::Broadcast));
		}
	}
}
