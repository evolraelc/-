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
	this->addChild(_map);

	_collidable = _map->getLayer("water");
	_collidable->setVisible(true);

	return true;
}


bool MapLayer::clickDownToDrag(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Layer*>(eventMouse->getCurrentTarget());
	Vec2 locationInNode = target->convertToNodeSpace(eventMouse->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	
	log("%d", _isDrag);
	_isDrag = true;
	_posBeginDrag = this->convertToNodeSpace(eventMouse->getLocation());
	return true;

	/*if (rect.containsPoint(locationInNode))
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


	if (_isDrag)
	{
		log("%d %d", this->getPosition().x, this->getPositionY());
		target->setPosition(target->getPosition() + (this->convertToNodeSpace(eventMouse->getLocation()) - _posBeginDrag));
	}
}

void MapLayer::clickUpToDrag(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Layer*>(event->getCurrentTarget());

	/*Vec2 lacationInNode = target->convertToNodeSpace(eventMouse->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	*/
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





bool Game::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	this->initMapLayer();

	//this->initMenu();
	
	return true;
}

void Game::initMapLayer()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_mapLayer = MapLayer::create();
	this->addChild(_mapLayer);
}

/*void Game::initVecMenuItem()
{
	for (int i = 0; i <= ITEM_AMOUNT; i++)
	{
		auto visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		MenuItemImage* menuItemImage = MenuItemImage::create(itemImageAdress[i][0], itemImageAdress[i][1], itemImageAdress[i][2]
			, [&](Ref *sender) {log("click"); });
			menuItemImage->setPosition(Vec2(200,-100));
	}
}
void Game::initMenu()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->initVecMenuItem();
	MenuItemImage* menuItemImage = MenuItemImage::create(itemImageAdress[0][0], itemImageAdress[0][1], itemImageAdress[0][2]
		, CC_CALLBACK_1(Game::onclick, this));
	menuItemImage->setPosition(Vec2(200, -100));
	auto mn = Menu::create(menuItemImage);
	this->addChild(mn,1);
}*/


Game* Game::createScene()
{
	return Game::create();
}





