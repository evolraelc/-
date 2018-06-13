#include"GameSceneController.h"

bool GameSceneController::init()
{
	if (!Node::init())
	{
		return false;
	}
	else
	{
		_gameScene = Game::create(); 
	}
}
