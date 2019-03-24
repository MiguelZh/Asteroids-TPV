#include "GameManager.h"
#include "Messages_defs.h"


GameManager::GameManager(SDLGame * game): Container(game), running_(false), gameOver_(true), score_(0), lives_(maxLives_)
, winner_(0), gameCtrl_(), scoreView_(), gameStatusView_(), livesViewer_(), fighterAsteroidCollision_(), bulletsAsteroidsCollision_()
{
	setId(msg::GameManager);
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

void GameManager::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);
	switch(msg.type_)
	{
	case msg::GAME_START:
		gameOver_ = false;
		winner_ = 0;
		lives_ = maxLives_;
		break;
	case msg::ROUND_START:
		running_ = true;
		getGame()->getServiceLocator()->getAudios()->playMusic(Resources::ImperialMarch);
		break;
	case msg::ASTEROID_DESTROYED:
		score_ +=  static_cast<const msg::AsteroidDestroyed&>(msg).points_;
		break;
	case msg::NO_MORE_ASTEROIDS:
		running_ = false;
		gameOver_ = true;
		winner_ = 1;
		getGame()->getServiceLocator()->getAudios()->haltMusic(); // halt = stop
		globalSend(this,msg::Message(msg::ROUND_OVER,msg::GameManager,msg::Broadcast));
		globalSend(this, msg::Message(msg::GAME_OVER, msg::GameManager, msg::Broadcast));
		break;
	case msg::FIGHTER_ASTEROID_COLLISION:
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0);
		running_ = false;
		lives_--;
		if (lives_ > 0) {
			globalSend(this, msg::Message(msg::ROUND_OVER, msg::GameManager, msg::Broadcast));
		}
		else { globalSend(this, msg::Message(msg::GAME_OVER, msg::GameManager, msg::Broadcast)); }
		break;
	default:
		break;
	}
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
