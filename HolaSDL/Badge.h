#pragma once
#include "GameObject.h"
#include "Container.h"
#include "ImageGC.h"

class Badge : public Container
{
protected:
	ImageGC badgeImage_;
public:
	Badge(SDLGame* game);
	~Badge();
	virtual void receive(const void* senderObj, const msg::Message& msg);
};

