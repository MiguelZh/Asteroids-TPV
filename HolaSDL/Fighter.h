#ifndef _AA
#define _AA

#include "GameObject.h"
#include "Container.h"
#include "DemoGC.h"
#include "DemoIC.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "BounceOnBorderPC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "RotationIC.h"
#include "ThrustIC.h"
#include"ReduceSpeedPC.h"
#include"GunIC.h"

class Fighter : public Container {
public:
	Fighter(SDLGame* game);
	virtual ~Fighter();
	virtual void receive(const void* senderObj, const msg::Message& msg);
private:
	ImageGC fighterImage_;	
	NaturalMovePC naturalMove_;
	ShowUpAtOppositeSidePC oppositeSide_;
	RotationIC rotation_;
	ThrustIC thrust_;
	ReduceSpeedPC reduceSpeed_;
	GunIC normalGun_;
	//BulletsShooter* bs_;
};

#endif _AA
