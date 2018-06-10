#include "cocos2d.h"
#include "GameScene.h"
USING_NS_CC;

bool Game::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_tileMap = TMXTiledMap::create("map/1.tmx");
	this->addChild(_tileMap, 0, 100);

	return true;
}


