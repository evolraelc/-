#include "SimpleAudioEngine.h"
#include "SettingScene.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* Setting::createScene()
{
	auto scene = Scene::create();
	auto layer = Setting::create();
	scene->addChild(layer);

	return scene;
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelpScene.cpp\n");
}

bool Setting::init()
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

	auto SoundOnMenuItem = MenuItemImage::create("On.ong", "On.png");
	auto SoundOffMenuItem = MenuItemImage::create("Off.ong", "Off.png");
	auto SoundToggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(Setting::menuSoundToggleCallback,this),
		SoundOffMenuItem, 
		SoundOnMenuItem,
		NULL);

	SoundToggleMenuItem->setPosition(500,500);

	auto MusicOnMenuItem = MenuItemImage::create("On.ong", "On.png");
	auto MusicOffMenuItem = MenuItemImage::create("Off.ong", "Off.png");
	auto MusicToggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(Setting::menuMusicToggleCallback,this), 
		MusicOffMenuItem, 
		MusicOnMenuItem,
		NULL);

	MusicToggleMenuItem->setPosition(500, 300);
Menu *mm2 = Menu::create(SoundOnMenuItem, MusicOffMenuItem, NULL);
	/*MenuItemFont::setFontName("Marker Felt");
	MenuItemFont::setFontSize(30);

	auto item = MenuItemFont::create("Back", CC_CALLBACK_1(Setting::menuSettingIsOkCallback, this));
	
	item->setPosition(200, -100);
	this->addChild(mm2);
	return true;*/
}


void Setting::menuSettingIsOkCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->popScene();
	if (isEffect)
	{
		SimpleAudioEngine::getInstance()->playEffect("2.mp3");
	}
}

void Setting::menuSoundToggleCallback(cocos2d::Ref* pSender)
{
	auto  soundToggleMenuItem = (MenuItemToggle*)pSender;
	if (isEffect)
	{
		SimpleAudioEngine::getInstance()->playEffect("2.mp3");
	}
	if (soundToggleMenuItem->getSelectedIndex() == 1)
	{
		isEffect = false;
	}
	else
	{
		isEffect = true;
		SimpleAudioEngine::getInstance()->playEffect("2.mp3");
	}
}

void Setting::menuMusicToggleCallback(cocos2d::Ref* pSender)
{
	auto  musicToggleMenuItem = (MenuItemToggle*)pSender;
	if (musicToggleMenuItem->getSelectedIndex() == 1)
	{
		SimpleAudioEngine::getInstance()->stopBackgroundMusic("1.mp3");
	}
	else
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic("1.mp3");
	}
	if (isEffect)
	{
		SimpleAudioEngine::getInstance()->playEffect("2.mp3");
	}
}

void Setting::OnEnter()
{
	Layer::onEnter();
}

void Setting::OnEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	isEffect = true;
	SimpleAudioEngine::getInstance()->playBackgroundMusic("1.mp3", true);
}

void Setting::OnExit()
{
	Layer::onExit();
}

void Setting::OnExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
}

void Setting::cleanup()
{
	Layer::cleanup();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("1.mp3");
}