#include"GameSceneController.h"
#include "Data/Architecture.h"
#include "Data/Player.h"
#include"cocos2d.h"
USING_NS_CC;

bool GameController::locationInit()
{
	if (!Node::init())
	{
		return false;
	}
	else
	{
		_gameScene = Game::create(); 

		EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();

		auto listener = EventListenerMouse::create();
		listener->onMouseDown = CC_CALLBACK_1(GameController::clickToBuild, this);//¼àÌýµØÍ¼²ã
		eventDispatcher->addEventListenerWithSceneGraphPriority
		(listener, _gameScene->getMapLayer());


		return true;
	}
}


void GameController::clickToBuild(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Sprite*>(eventMouse->getCurrentTarget());

	if (this->_gameScene->_menuLayer->_isChosen)
	{
		this->_gameScene->_menuLayer->_isChosen = false;
		if (this->canBuilding())
		{
			this->addBuilding(this->_gameScene->_menuLayer->convertToNodeSpace
			(eventMouse->getLocation()));
		}
	}
}

void GameController::clickToRun(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Sprite*>(eventMouse->getCurrentTarget());

	if (this->_gameScene->_menuLayer->_isChosen)
	{
		if (this->canMan())
		{
			this->addMan(this->_gameScene->_menuLayer->convertToNodeSpace
			(eventMouse->getLocation()));
			this->_gameScene->_menuLayer->_isChosen = false;
		}
	}
}
bool GameController::canMan()
{
	return true;
}

void GameController::addMan(cocos2d::Vec2& Pos)
{

}

bool GameController::canBuilding()
{
	return true;
}
void GameController::addBuilding(cocos2d::Vec2& Pos)
{
   
}