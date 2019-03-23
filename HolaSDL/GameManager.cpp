#include "GameManager.h"



GameManager::GameManager(SDLGame * game): Container(game), running_(false), gameOver_(true), score_(0), lives_(maxLives_)
, winner_(0), gameCtrl_(), scoreView_(), gameStatusView_(), livesViewer_()/*, fighterAsteroidCollision_(), bulletsAsteroidsCollision_()*/
{

}


GameManager::~GameManager()
{
}

bool GameManager::getRunning()
{
	return running_;
}
