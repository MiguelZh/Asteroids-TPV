#include "LivesViewer.h"



LivesViewer::LivesViewer()
{
}


LivesViewer::~LivesViewer()
{
}

void LivesViewer::render(Container * c, Uint32 time)
{
	Texture msg0(c->getGame()->getRenderer(),
		"Score ",
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });
	msg0.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 2 - 400 / 2, c->getGame()->getWindowHeight() - 500);
}
