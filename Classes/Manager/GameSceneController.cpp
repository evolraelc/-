#include"GameSceneController.h"
#include "Architecture.h"
#include "Player.h"
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

		EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();//
		auto listener1 = EventListenerMouse::create();
		listener1->onMouseDown = CC_CALLBACK_1(GameController::clickToChoose,this);//监听菜单层每一个精灵
		for (int i = 0; i <= ITEM_AMOUNT; i++)
		{
			eventDispatcher->addEventListenerWithSceneGraphPriority
			(listener1->clone(),_gameScene->getMenuLayer()->getChildByTag(spriteTag[i]));
		}
		auto listener2 = EventListenerMouse::create();
		listener2->onMouseDown = CC_CALLBACK_1(GameController::clickToBuild, this);//监听地图层
		eventDispatcher->addEventListenerWithSceneGraphPriority
		(listener2, _gameScene->getMapLayer());


		return true;
	}
}

bool GameController::clickToChoose(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Sprite*>(eventMouse->getCurrentTarget());

	Vec2 locationInNode = target->convertToNodeSpace(eventMouse->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	if (rect.containsPoint(locationInNode))
	{
		this->_gameScene->_menuLayer->_isChosen = true;
		this->_gameScene->_menuLayer->_kind = target->getTag();
		return true;
	}
}

void GameController::clickToBuild(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Sprite*>(eventMouse->getCurrentTarget());

	if (this->_gameScene->_menuLayer->_isChosen)
	{
		if (this->canBuilding())
		{
			this->addBuilding(this->_gameScene->_menuLayer->convertToNodeSpace
			(eventMouse->getLocation()));
			this->_gameScene->_menuLayer->_isChosen = false;
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