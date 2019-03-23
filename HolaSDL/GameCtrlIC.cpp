#include "GameCtrlIC.h"
#include "Messages_defs.h"
#include "GameManager.h"

GameCtrlIC::GameCtrlIC()
{
}

GameCtrlIC::~GameCtrlIC()
{
}

void GameCtrlIC::handleInput(Container* c, Uint32 time, const SDL_Event& event)
{
	GameManager * gm = static_cast<GameManager*>(c);

	if (!gm->getRunning() && event.key.keysym.sym == SDLK_RETURN) {
		if (gm->getGameOver()) {
			c->globalSend(this, msg::Message(msg::GAME_START, c->getId(), msg::Broadcast));
		}
		c->globalSend(this, msg::Message(msg::ROUND_START, c->getId(), msg::Broadcast));
	}
}
