#include "GameManager.h"



GameManager::GameManager(SDLGame * game): Container(game), running_(false), gameOver_(true), score_(0), lives_(maxLives_)
, winner_(0), gameCtrl_(), scoreView_(), gameStatusView_(), livesViewer_(), fighterAsteroidCollision_(), bulletsAsteroidsCollision_()
{
	addC(&gameCtrl_);
	addC(&scoreView_);
	addC(&livesViewer_);
	addC(&gameStatusView_);
	addC(&fighterAsteroidCollision_);
	addC(&bulletsAsteroidsCollision_);
}


GameManager::~GameManager()
{
}

bool GameManager::getRunning()
{
	return running_;
}

int GameManager::getLives()
{
	return lives_; 
}

int GameManager::getMaxLives() {
	return maxLives_;
}

int GameManager::getScore()
{
	return score_;
}

int GameManager::getWinner() {
	return winner_;
}

bool GameManager::getGameOver() {
	return gameOver_;
}
