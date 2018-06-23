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

	return true;
}

bool MapLayer::clickDownToDrag(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Layer*>(eventMouse->getCurrentTarget());
	/*Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);*/
	

	_isDrag = true;
	_posBeginDrag = this->convertToNodeSpace(eventMouse->getLocation());
	return true;

	/*if (rect.containsPoint(locationInNode))尝试加一步判断，失败！
	{
		_isDrag = true;
		_posBeginDrag = this->convertToNodeSpace(eventMouse->getLocation());
		return true;
	}
	else
	{
		return false;
	}*/

}

void MapLayer::clickMoveToDrag(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Layer*>(event->getCurrentTarget());

	auto tempLocation = (target->getPosition() + (target->convertToNodeSpace(eventMouse->getLocation()) - _posBeginDrag));
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto mapSize = _map->getMapSize();
	if (_isDrag)
	{
		/*
		if (tempLocation.x > 0) { tempLocation.x = 0; }
		if (tempLocation.x < visibleSize.width- mapSize.width) { tempLocation.x = visibleSize.width - mapSize.width; }尝试防止拉出界，失败！
		if (tempLocation.y > 0) { tempLocation.y = 0; }
		if (tempLocation.y < visibleSize.height - mapSize.height) { tempLocation.y = visibleSize.height - mapSize.height; }
		*/
		target->setPosition(tempLocation);
		log("%d   %d", tempLocation.x, tempLocation.y);

	}
}

void MapLayer::clickUpToDrag(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Layer*>(event->getCurrentTarget());

	_isDrag = false;
}

void MapLayer::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerMouse::create();

	listener->onMouseDown = CC_CALLBACK_1(MapLayer::clickDownToDrag, this);
	listener->onMouseMove = CC_CALLBACK_1(MapLayer::clickMoveToDrag, this);
	listener->onMouseUp = CC_CALLBACK_1(MapLayer::clickUpToDrag, this);

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
	_kind = 0;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	 
	auto yellow = Sprite::create("yellow.png");
	yellow->setAnchorPoint(Vec2(1, 0.5));
	yellow->setPosition(Vec2(visibleSize.width, 0.5*visibleSize.height));
	this->addChild(yellow);

	for (int i = 1; i <= ITEM_AMOUNT ;++i)
	{
		auto item = MenuItemImage::create(imageAdress[i - 1], imageAdress[i - 1], imageAdress[i - 1],
			[&](Ref *pSender) 
		{_isChosen = true;
		_kind = i; });

		item->setPosition(Vec2(visibleSize.width-25, visibleSize.height*(i+1) / 10));
		this->addChild(item, 1, i);										//点击造兵键功能未完善
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
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	this->initMapLayer();
	this->initMenuLayer();
	
	return true;
}

void Game::initMapLayer()
{
	_mapLayer = MapLayer::create();
	_mapLayer->setPosition(Vec2::ZERO);
	this->addChild(_mapLayer,0);
}

void Game::initMenuLayer()
{
	_menuLayer = MenuLayer::create();
	_menuLayer->setPosition(Vec2::ZERO);
	this->addChild(_menuLayer,1);
}







