#include "SumUpGC.h"
#include "GameManager.h"
#include "RoundOverSumUp.h"
SumUpGC::SumUpGC()
{
}

SumUpGC::~SumUpGC()
{
}

void SumUpGC::render(Container* c, Uint32 time)
{
	RoundOverSumUp* gm = static_cast<RoundOverSumUp*>(c);
	string text = "";

	if (!gm->getRunning()) {
		text += "Shoot " + to_string(gm->getBullets()) + " bullets and detroyed " + to_string(gm->getAsteroids()) + " asteroids";
		Texture msg0(c->getGame()->getRenderer(),
			text,
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
				Resources::ARIAL24)), { COLOR(0x0022ffff) });
		msg0.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - msg0.getWidth() / 2, c->getGame()->getWindowHeight() - 200);
	}

}
