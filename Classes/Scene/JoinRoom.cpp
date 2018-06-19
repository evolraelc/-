#include"JoinRoom.h"

USING_NS_CC;
Scene* JoinRoom::createScene()
{
	return JoinRoom::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MenuScene.cpp\n");
}

bool JoinRoom::init()
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
	MenuItemFont::setFontSize(60);

	auto item1 = MenuItemFont::create("Start", CC_CALLBACK_1(JoinRoom::menuStartCallback, this));
	auto item2 = MenuItemFont::create("Help", CC_CALLBACK_1(JoinRoom::menuHelpCallback, this));
	auto item3 = MenuItemFont::create("Back", CC_CALLBACK_1(JoinRoom::menuGetCallback, this));
	Menu *mm = Menu::create(item1, item2, item3, NULL);
	mm->alignItemsVertically();
	this->addChild(mm);

	return true;
}

void JoinRoom::menuGetCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->popScene();
}

void JoinRoom::menuStartCallback(cocos2d::Ref* pSender)
{
	auto st = Game::createScene();
	Director::getInstance()->pushScene(st);
}

void JoinRoom::menuHelpCallback(cocos2d::Ref* pSender)
{
	auto he = Help::createScene();
	Director::getInstance()->pushScene(he);
}