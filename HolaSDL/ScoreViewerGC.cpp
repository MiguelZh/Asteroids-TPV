#include "ScoreViewerGC.h"
#include  "GameManager.h"


ScoreViewerGC::ScoreViewerGC()
{
}


ScoreViewerGC::~ScoreViewerGC()
{
}

void ScoreViewerGC::render(Container * c, Uint32 time)
{
	GameManager * gm = static_cast<GameManager*>(c); // static cast to get score of gm

	Texture msg0(c->getGame()->getRenderer(),
		"Score " + std::to_string(gm->getScore()),
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });
	msg0.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 2 -400/ 2, c->getGame()->getWindowHeight() - 600);

}
