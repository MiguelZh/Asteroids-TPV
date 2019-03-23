#include "LivesViewer.h"
#include "GameManager.h"


LivesViewer::LivesViewer()
{
}


LivesViewer::~LivesViewer()
{
}

void LivesViewer::render(Container * c, Uint32 time)
{
	GameManager* gm = static_cast<GameManager*>(c); // to get the lives of gamemanager

	Texture msg0(c->getGame()->getRenderer(),
		"Lives " +  std::to_string(gm->getLives()),
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });
	msg0.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() -150, c->getGame()->getWindowHeight() - 600);
}
