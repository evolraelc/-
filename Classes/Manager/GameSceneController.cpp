#include"GameSceneController.h"
#include "Scene/GameOver.h"
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

		_yes = false;
		_gameover = false;
		_initmoney = 100;
		EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();

	
		auto listener1 = EventListenerMouse::create();
		listener1->onMouseDown = CC_CALLBACK_1(GameController::clickToBuild, this);//监听地图层
		eventDispatcher->addEventListenerWithSceneGraphPriority
		(listener1, _gameScene->getMapLayer());

        auto listener2 = EventListenerKeyboard::create();
		listener2->onKeyPressed = CC_CALLBACK_2(GameController::add, this);//监听地图层
		eventDispatcher->addEventListenerWithSceneGraphPriority
		(listener2, _gameScene->getMapLayer());

		auto listener3 = EventListenerMouse::create();
		listener3->onMouseDown= CC_CALLBACK_1(GameController::onTouchBegan, this);//监听地图层
		eventDispatcher->addEventListenerWithSceneGraphPriority
		(listener3, _gameScene->getMapLayer());
	    
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

	if (this->_gameScene->_menuLayer->_isChosen&&this->_gameScene->_menuLayer->_isAdding)
	{
		this->_gameScene->_menuLayer->_isChosen = false;
		this->_gameScene->_menuLayer->_isAdding = false;
		this->initEnemy(this->_gameScene->_mapLayer->convertToNodeSpace
		(eventMouse->getLocation()));
	}
	else
	{
		auto kind = this->_gameScene->_menuLayer->_kind;
		this->_gameScene->_menuLayer->_isChosen = false;
		this->addBuilding(this->_gameScene->_mapLayer->convertToNodeSpace
		(Vec2(eventMouse->getLocation().x,300-eventMouse->getLocation().y)), kind); 
	}
}

/*void GameController::clickToAddMan(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Sprite*>(eventMouse->getCurrentTarget());
	if (this->_gameScene->_menuLayer->_isAdding)
	{
		auto kind = this->_gameScene->_menuLayer->_kind;
		this->_gameScene->_menuLayer->_isAdding = false;
		if (this->canAddMan())
		{
			initEnemy();
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

void GameController::clickToChoose(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Sprite*>(eventMouse->getCurrentTarget());

	for ()
	{
		auto rect = 该精灵的Rect;
		auto position = this->_gameScene->_menuLayer->convertToNodeSpace
		(eventMouse->getLocation());
		if (rect->containsPoint(position))
		{
			//把精灵设为选中
		}
	}
}*/

bool GameController::canMan()
{
	return true;
}
bool GameController::canAddMan()
{
	return true;
}

bool GameController::canBuilding()
{
	return true;
}
void GameController::addBuilding(cocos2d::Vec2& Pos, int kind)
{
		Sprite *basement = Sprite::create("basement.png");
		Sprite *powerplant = Sprite::create("powerplant.png");
		Sprite *minefield = Sprite::create("minefield.png");
		Sprite *barracks = Sprite::create("barracks.png");
		Sprite *warfactory = Sprite::create("warfactory.png");
		Sprite *tank = Sprite::create("tank.png");
		switch (kind)
		{
		case 1:
			basement->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(basement);
			this->setTag(1);
			break;
		case 2:
			powerplant->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(powerplant);
			this->setTag(2);
			break;
		case 3:
			minefield->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(minefield);
			this->setTag(3);
			break;
		case 4:
			barracks->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(barracks);
			this->setTag(4);
			break;
		case 5:
			warfactory->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(warfactory);
			this->setTag(5);
			break;
		case 7:
			warfactory->setPosition(Pos);
			this->_gameScene->_mapLayer->addChild(warfactory);
			this->setTag(7);
			break;
		}
}

void GameController::update(float dt)
{
	static float curTime = 0;
	curTime += dt;
	if (curTime > dt * 2.f )
	{
		curTime -= dt * 2.f;
	}
}


void GameController::initEnemy(cocos2d::Vec2& Pos)
{
	ENEMY_MOVE_SPEED = 100.f;
	auto runAnimation = Animation::create();
	for (int i = 0; i<5; ++i)
	{
		auto fileName = StringUtils::format("enemy/run%d.png", i);
		runAnimation->addSpriteFrameWithFile(fileName);
	}
	runAnimation->setDelayPerUnit(0.1f);
	_runAnim = Animate::create(runAnimation);
	_runAnim->retain();

	auto standAnimation = Animation::create();
	for (int i = 0; i<3; ++i)
	{
		auto fileName = StringUtils::format("enemy/stand%d.png", i);
		standAnimation->addSpriteFrameWithFile(fileName);
	}
	standAnimation->setDelayPerUnit(0.2f);
	_standAnim = Animate::create(standAnimation);
	_standAnim->retain();

	_enemy = Sprite::create();
	_enemy->setPosition(Pos);
	this->_gameScene->_mapLayer->addChild(_enemy);
	_enemy->runAction(RepeatForever::create(_standAnim));
	_yes = true;
}


void GameController::runAndStand(const Vec2& pos)
{
	if (600 - _enemy->getPosition().x > 20 && 300 - _enemy->getPosition().y > 20)
	{
		float distance = _enemy->getPosition().getDistance(pos);
		auto moveTo = MoveTo::create(distance / ENEMY_MOVE_SPEED, pos);
		auto standCall = CallFunc::create([=] {
			_enemy->stopAllActions();
			_enemy->runAction(RepeatForever::create(_standAnim));
		});
		_enemy->stopAllActions();
		_enemy->setFlippedX(pos.x < _enemy->getPosition().x);
		_enemy->runAction(RepeatForever::create(_runAnim));
		_enemy->runAction(Sequence::createWithTwoActions(moveTo, standCall));
	}
	else
	{
		this->_gameScene->_mapLayer->removeChildByTag(100);
		Director::getInstance()->end();
	}
	
}


bool GameController::onTouchBegan(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Sprite*>(eventMouse->getCurrentTarget());
	auto a = eventMouse->getLocation();
	log("%f  %f", a.x, a.y);
	if (_yes)
	{
		this->runAndStand(this->_gameScene->_mapLayer->convertToNodeSpace
		(Vec2(a.x, 300 - a.y)));
	}
	return true;
}

void GameController::add(EventKeyboard::KeyCode code, Event *event)
{
	auto eventMouse = static_cast<EventKeyboard*>(event);
	auto target = static_cast<Layer*>(eventMouse->getCurrentTarget());

	switch (code)
	{
	case EventKeyboard::KeyCode::KEY_1:
		this->_gameScene->_menuLayer->_isChosen = true;
		this->_gameScene->_menuLayer->_kind = 1;
		break;
	case EventKeyboard::KeyCode::KEY_2:
		this->_gameScene->_menuLayer->_isChosen = true;
		this->_gameScene->_menuLayer->_kind = 2;
		break;
	case EventKeyboard::KeyCode::KEY_3:
		this->_gameScene->_menuLayer->_isChosen = true;
		this->_gameScene->_menuLayer->_kind = 3;
		break;
	case EventKeyboard::KeyCode::KEY_4:
		this->_gameScene->_menuLayer->_isChosen = true;
		this->_gameScene->_menuLayer->_kind = 4;
		break;
	case EventKeyboard::KeyCode::KEY_5:
		this->_gameScene->_menuLayer->_isChosen = true;
		this->_gameScene->_menuLayer->_kind = 5;
		break;
	case EventKeyboard::KeyCode::KEY_6:
		this->_gameScene->_menuLayer->_isChosen = true;
		this->_gameScene->_menuLayer->_isAdding = true;
		this->_gameScene->_menuLayer->_kind = 6;

		break;
	case EventKeyboard::KeyCode::KEY_7:
		this->_gameScene->_menuLayer->_isChosen = true;
		this->_gameScene->_menuLayer->_isAdding = true;
		this->_gameScene->_menuLayer->_kind = 7;
		break;
	}
}

void GameController::money_had(int kind)
{
	int realM = _initmoney - _price[kind];

}

void GameController::gameIsOver()
{
}