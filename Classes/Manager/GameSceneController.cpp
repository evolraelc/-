#include"GameSceneController.h"
#include "Data/Architecture.h"
#include "Data/Player.h"
#include"cocos2d.h"
USING_NS_CC;

bool GameController::init()
{
	if (!Node::init())
	{
		return false;
	}
	else
	{
		_gameScene = Game::create(); 


		EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();

		auto listener1 = EventListenerMouse::create();
		listener1->onMouseDown = CC_CALLBACK_1(GameController::clickToBuild, this);//¼àÌýµØÍ¼²ã
		eventDispatcher->addEventListenerWithSceneGraphPriority
		(listener1, _gameScene->getMapLayer());

		auto listener2 = EventListenerMouse::create();
		listener2->onMouseDown = CC_CALLBACK_1(GameController::clickToAddMan, this);//¼àÌýµØÍ¼²ã
		eventDispatcher->addEventListenerWithSceneGraphPriority
		(listener2, _gameScene->getMapLayer());


		return true;
	}
}

GameController* GameController::create()
{
	auto gameController = new GameController();
	if (gameController)
	{
		gameController->init();
		return gameController;
	}
	else
	{
		return nullptr;
	}
}

void GameController::clickToBuild(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Sprite*>(eventMouse->getCurrentTarget());

	if (this->_gameScene->_menuLayer->_isChosen||1)
	{
		auto kind = this->_gameScene->_menuLayer->_kind;
		this->_gameScene->_menuLayer->_isChosen = false;
		if (this->canBuilding())
		{
			this->addBuilding(this->_gameScene->_menuLayer->convertToNodeSpace
			(eventMouse->getLocation()),5);
		}
	}
}

void GameController::clickToAddMan(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Sprite*>(eventMouse->getCurrentTarget());
	if (this->_gameScene->_menuLayer->_isAdding)
	{
		
		this->_gameScene->_menuLayer->_isAdding = false;
		if (this->canAddMan())
		{
			this->addMan(this->_gameScene->_menuLayer->convertToNodeSpace
			(eventMouse->getLocation()),6);
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
			
			this->playerMove(this->_gameScene->_menuLayer->convertToNodeSpace
			(eventMouse->getLocation()));
			this->_gameScene->_menuLayer->_isChosen = false;
		}
	}
}

void GameController::playerMove(cocos2d::Vec2& Pos)
{



}
bool GameController::canMan()
{
	return true;
}
bool GameController::canAddMan()
{
	return true;
}
void GameController::addMan(cocos2d::Vec2& Pos,int kind)
{
	Sprite *soldier= Sprite::create("soldier.png");
	Sprite *tank = Sprite::create("tank.png");
	if (kind == 6)
	{
		soldier->setPosition(Pos);
		this->_gameScene->_mapLayer->addChild(soldier);
	}
	else if (kind == 7)
	{
		tank->setPosition(Pos);
		this->_gameScene->_mapLayer->addChild(tank);
	}
	
}

bool GameController::canBuilding()
{
	return true;
}
void GameController::addBuilding(cocos2d::Vec2& Pos, int kind)
{
	Sprite *basement = Sprite::create("basement.png");
	Sprite *powerplant = Sprite::create("powerplant.png");
	Sprite *minefield = Sprite::create("minefield,png");
	Sprite *barracks = Sprite::create("barracks.png");
	Sprite *warfactory = Sprite::create("warfactory.png");
		switch (kind)
		{
		case 1:
			basement->setPosition(Pos);    
			this->_gameScene->_mapLayer->addChild(basement);
			break;
		case 2:
			powerplant->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(powerplant);
			break;
		case 3:
			minefield->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(minefield);
			break;
		case 4:
			barracks->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(barracks);
			break;
		case 5:
			warfactory->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(warfactory);
			break;
		};
	

}