#pragma once
#include"InputComponent.h"
#include "GameManager.h"
class GameCtrlIC : public InputComponent
{
public:
	GameCtrlIC();
	virtual ~GameCtrlIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event)
};

