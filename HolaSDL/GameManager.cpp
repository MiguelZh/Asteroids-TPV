#include "GameManager.h"



GameManager::GameManager()
{
	running_ = false;
	gameOver_ = true;
	score_ = 0;
	lives_ = maxLives_;
	winner_ = 0;
}


GameManager::~GameManager()
{
}

bool GameManager::getRunning()
{
	return running_;
}
