#include "SimpleAudioEngine.h"
#include "MenuScene.h"
#include "HelpScene.h"
#include "GameScene.h"
#include "SettingScene.h"
#include"Manager/GameSceneController.h"
USING_NS_CC;
using namespace CocosDenshion;
#define SOUND_KEY "sound_key"
#define MUSIC_KEY "music_key"
Scene* Menu_S::createScene()
{
	auto scene = Scene::create();
	auto layer = Menu_S::create();
	scene->addChild(layer);

	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MenuScene.cpp\n");
}

bool Menu_S::init()
{

	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("Menu.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(bg);

	MenuItemFont::setFontName("Marker Felt");
	MenuItemFont::setFontSize(40);

	auto item1 = MenuItemFont::create("Start", CC_CALLBACK_1(Menu_S::menuStartCallback, this));
	auto item2 = MenuItemFont::create("Help", CC_CALLBACK_1(Menu_S::menuHelpCallback, this)); 
	auto item3 = MenuItemFont::create("Settings", CC_CALLBACK_1(Menu_S::menuSettingCallback, this));
	auto item4= MenuItemFont::create("Back", [&](Ref* pSender) { Director::getInstance()->popScene(); });
	Menu *mm = Menu::create(item1, item2,item3,item4,NULL);
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

void Menu_S::menuSettingCallback(cocos2d::Ref* pSender)
{
	auto gc =Setting::createScene();
	Director::getInstance()->pushScene(gc);

	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
		
			SimpleAudioEngine::getInstance()->playEffect("2.mp3");
	}
}


void Menu_S::menuHelpCallback(cocos2d::Ref* pSender)
{
	auto he = Help::createScene();
	Director::getInstance()->pushScene(he);
}


void Menu_S::onEnter()
{
	Layer::onEnter();
	log("HelloWorld onEnter");
}


void Menu_S::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("HelloWorld onEnterTransitionDidFinish");


	//²¥·Å  
	if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY)) {
			SimpleAudioEngine::getInstance()->playBackgroundMusic("1.mp3", true);
	}
}


void Menu_S::onExit()
{
	Layer::onExit();
	log("HelloWorld onExit");
}


void Menu_S::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("HelloWorld onExitTransitionDidStart");
}


void Menu_S::cleanup()
{
	Layer::cleanup();
	log("HelloWorld cleanup");
	//Í£Ö¹  
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("1.mp3");
}