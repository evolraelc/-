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
	this->initMenu();

	return true;
}

void Game::initMap()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_tileMap = TMXTiledMap::create("1.tmx");
	this->addChild(_tileMap);

	//_collidable = _tileMap->getLayer("water");
	//_collidable->setVisible(false);
}


void Game::initMenu()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto menu = Menu::create();
	for (int i = 0; i <= BUTTON_AMOUNT; i++)
	{
		auto button = cocos2d::ui::Button::create("button/Iron.png", "button/Iron.png", "button/Iron.png");
		button->setPosition(Vec2(origin.x + 0.8*visibleSize.width, origin.y + (i + 1)*0.1*visibleSize.height));
		menu->addChild(button);
	}
	this->addChild(menu);
}


Game* Game::createScece()
{
	return Game::create();
}