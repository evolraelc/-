#include "SimpleAudioEngine.h"
#include "MenuScene.h"
#include "HelpScene.h"
#include "GameScene.h"
#include"Manager/GameSceneController.h"
USING_NS_CC;

Scene* Menu_S::createScene()
{
	return Menu_S::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MenuScene.cpp\n");
}

bool Menu_S::init()
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

	auto item1 = MenuItemFont::create("Start", CC_CALLBACK_1(Menu_S::menuStartCallback, this));
	auto item2 = MenuItemFont::create("Help", CC_CALLBACK_1(Menu_S::menuHelpCallback, this)); 
	auto item3= MenuItemFont::create("Back", [&](Ref* pSender) { Director::getInstance()->popScene(); });
	Menu *mm = Menu::create(item1, item2,item3,NULL);
	mm->alignItemsVertically();
	this->addChild(mm);

	return true;
}

void Menu_S::menuGetCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->popScene();
}

void Menu_S::menuStartCallback(cocos2d::Ref* pSender)
{
	auto gc = GameController::create();
	Director::getInstance()->pushScene(gc->getGameScene());
}

void Menu_S::menuHelpCallback(cocos2d::Ref* pSender)
{
	auto he = Help::createScene();
	Director::getInstance()->pushScene(he);
}