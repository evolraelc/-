#include "GameScene.h"
#include"ui/CocosGUI.h"
USING_NS_CC;
//MapLayer的函数定义


bool MapLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	_map = TMXTiledMap::create("tiled_map.tmx");
	_map->setAnchorPoint(Vec2::ZERO);
	_map->setPosition(Vec2::ZERO);
	this->addChild(_map);
   
	_collidable = _map->getLayer("water");
	_collidable->setVisible(true); 
	Sprite* _boss = Sprite::create("soldier.png");
	_boss->setPosition(600,300);
	_boss->setTag(100);
	this->addChild(_boss);
	return true;
}

void MapLayer::move(EventKeyboard::KeyCode code, Event *event)
{
	auto eventMouse = static_cast<EventKeyboard*>(event);
	auto target = static_cast<Layer*>(eventMouse->getCurrentTarget());

	auto nowPosition = target->getPosition();
	auto tempPosition = nowPosition;
	float mapWidth = _map->getMapSize().width*_map->getTileSize().width;
	float mapHeight = _map->getMapSize().height*_map->getTileSize().height;
	float visibleSizeWidth = 1800;
	float visibleSizeHeight = 800;

	switch (code)
	{
	case EventKeyboard::KeyCode::KEY_W:
		tempPosition += Vec2(0, -10);
		log("%f,%f", tempPosition.y, visibleSizeHeight - mapHeight);
		if (tempPosition.y < -300) { break; }//有问题我不知道这个窗口大小 总是出错这个数是我自己试出来的
		target->setPosition(tempPosition);
		break;
	case EventKeyboard::KeyCode::KEY_A:
		tempPosition += Vec2(10, 0);
		if (tempPosition.x>0) { break; }
		target->setPosition(tempPosition);
		break;
	case EventKeyboard::KeyCode::KEY_S:
		tempPosition += Vec2(0, 10);
		if (tempPosition.y >0) { break; }
		target->setPosition(tempPosition);
		break;
	case EventKeyboard::KeyCode::KEY_D:
		tempPosition += Vec2(-10, 0);
		//if (tempPosition.x <visibleSizeWidth - mapWidth) { break; }
		target->setPosition(tempPosition);
		break;
	}
}

void MapLayer::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(MapLayer::move, this);

	EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority
	(listener, this);
}

void MapLayer::onExit()
{
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}






//MEnuLayer函数定义
bool MenuLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	_isChosen = false;
	_isAdding = false;
	_kind = 0;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto yellow = Sprite::create("yellow.png");
	yellow->setAnchorPoint(Vec2(1, 0.5));
	yellow->setPosition(Vec2(visibleSize.width, 0.5*visibleSize.height));
	this->addChild(yellow);

	for (int i = 1; i <= ITEM_AMOUNT; ++i)
	{
		auto item = MenuItemImage::create(imageAdress[i - 1], imageAdress[i - 1], imageAdress[i - 1],
			[&](Ref *pSender)
		{_isChosen = true;
		_kind = this->getTag();
		if (_kind == zaobing || _kind == zaoche) { _isAdding = true; }; });

		item->setPosition(Vec2(visibleSize.width - 25, visibleSize.height*(i + 1) / 10));
		this->addChild(item, 1, i);
	}


	return true;

}

//Game函数定义
Game* Game::createScene()
{
	return Game::create();
}

bool Game::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Size(1800, 800);
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	this->initMapLayer();
	this->initMenuLayer();

	return true;
}

void Game::initMapLayer()
{
	_mapLayer = MapLayer::create();
	_mapLayer->setPosition(Vec2::ZERO);
	this->addChild(_mapLayer, 0);
}

void Game::initMenuLayer()
{
	_menuLayer = MenuLayer::create();
	_menuLayer->setPosition(Vec2::ZERO);
	this->addChild(_menuLayer, 1);
}

Game* Game::create()
{
	Game* game = new Game();
	if (!game->init())
	{
		return nullptr;
	}
	return game;
}




