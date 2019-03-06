#include "GameStatusViewGC.h"



GameStatusViewGC::GameStatusViewGC()
{
}


GameStatusViewGC::~GameStatusViewGC()
{
}

void GameStatusViewGC::render(Container * c, Uint32 time)
{
	Texture msg0(c->getGame()->getRenderer(),
		"Game Over",
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });
	msg0.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 2 - msg0.getWidth() / 2, c->getGame()->getWindowHeight() - 150);

	if (true) {
		Texture msg1(c->getGame()->getRenderer(),
			"Press ENTER to Continue",
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x00ff22ff) });
		msg1.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - msg1.getWidth() / 2, c->getGame()->getWindowHeight() - 100);
	}
	else {
		Texture msg1(c->getGame()->getRenderer(),
			"Press ENTER to Start a New Game",
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x00ff22ff) });
		msg1.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - msg1.getWidth() / 2, c->getGame()->getWindowHeight() - 100);
	}
}
