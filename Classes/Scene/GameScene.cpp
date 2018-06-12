#include "GameScene.h"
#include"ui/CocosGUI.h"
USING_NS_CC;

bool Game::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	this->initMap();
	//this->initMenu();

	return true;
}

void Game::initMap()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_tileMap = TMXTiledMap::create("tiled_map.tmx");
	auto layer = Layer::create();
	layer->addChild(_tileMap);
	this->addChild(layer, 0, MAP_LAYER_TAG);

	_collidable = _tileMap->getLayer("water");
	_collidable->setVisible(true);
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


void Game::onEnter()
{
	Scene::onEnter();
	auto listener = EventListenerMouse::create();

	listener->onMouseDown = CC_CALLBACK_1(Game::clickDown, this);
	listener->onMouseMove = CC_CALLBACK_1(Game::clickMove, this);
	listener->onMouseUp = CC_CALLBACK_1(Game::clickUp, this);

	EventDispatcher *eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority
	(listener, this->getChildByTag(MAP_LAYER_TAG));
}

void Game::onExit()
{
	Scene::onExit();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}

bool Game::clickDown(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	//为什么不行？auto target = static_cast<Layer*>(eventMouse->getCurrentTarget);
	auto target = (eventMouse->getCurrentTarget);
	Vec2 locationInNode = target->convertToNodeSpace(eventMouse->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	if (rect.containsPoint(locationInNode))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Game::clickMove(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Layer*>(event->getCurrentTarget());
	target->setPosition(target->getPosition() + eventMouse->getDelta());
}

void Game::clickUp(Event *event)
{
	auto eventMouse = static_cast<EventMouse*>(event);
	auto target = static_cast<Layer*>(event->getCurrentTarget());

	Vec2 lacationInNode = target->convertToNodeSpace(eventMouse->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

}