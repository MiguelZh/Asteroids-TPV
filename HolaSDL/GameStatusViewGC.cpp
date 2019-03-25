#include "GameStatusViewGC.h"
#include "GameManager.h"


GameStatusViewGC::GameStatusViewGC()
{
}


GameStatusViewGC::~GameStatusViewGC()
{
}

void GameStatusViewGC::render(Container * c, Uint32 time)
{

	GameManager* gm = static_cast<GameManager*>(c);
	string textOver;
	string text;

	if (!gm->getRunning()) {
		if (gm->getGameOver()) {
			switch (gm->getWinner()) {
			case 0:
				textOver = " ";
				break;
			case 1:
				textOver = "Game Over, Asteroids Won :(";
				break;
			case 2:
				textOver = "Game Over, Fighter Won! :)";
				break;
			}
			Texture msg0(c->getGame()->getRenderer(),
				textOver,
				*(c->getGame()->getServiceLocator()->getFonts()->getFont(
					Resources::ARIAL24)), { COLOR(0x0022ffff) });
			msg0.render(c->getGame()->getRenderer(),
				c->getGame()->getWindowWidth() / 2 - msg0.getWidth() / 2, c->getGame()->getWindowHeight() - 150);

			text = "Press ENTER to Start a New Game";
		}
		else text = "Press ENTER to Continue";

		Texture msg1(c->getGame()->getRenderer(),
			text,
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x00ff22ff) });
		msg1.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - msg1.getWidth() / 2, c->getGame()->getWindowHeight() - 100);
	}
	
}
