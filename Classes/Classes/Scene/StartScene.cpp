#include "StartScene.h"
USING_NS_CC;

Scene* Start::createScene()
{
	return Start::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartScene.cpp\n");
}

bool Start::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("Menu.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(bg);

	MenuItemFont::setFontName("Marker Felt");
	MenuItemFont::setFontSize(30);

	auto item = MenuItemFont::create("Back", CC_CALLBACK_1(Start::menuStartIsOkCallback, this));
	Menu *mm1 = Menu::create(item,  NULL);
	item->setPosition(200, -100);
	this->addChild(mm1);

	a = 0;
	TMXTiledMap *_tileMap = TMXTiledMap::create("1.tmx");
	_tileMap->setAnchorPoint(Vec2(0.5,0.5));
	_tileMap->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(_tileMap);

	return true;
}


void Start::menuStartIsOkCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->popScene();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             