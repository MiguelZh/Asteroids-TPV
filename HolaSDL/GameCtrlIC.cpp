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
	//solo al pulsar return se llamara a este mensaje
	c->globalSend(this, msg::Message(msg::GAME_START, c->getId(), msg::Broadcast));
	//si se empieza nueva partida, siempre se envia
	c->globalSend(this, msg::Message(msg::ROUND_START, c->getId(), msg::Broadcast));
}
