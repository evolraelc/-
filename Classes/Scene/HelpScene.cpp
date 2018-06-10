#include "SimpleAudioEngine.h"
#include "HelpScene.h"
USING_NS_CC;

Scene* Help::createScene()
{
	return Help::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelpScene.cpp\n");
}

bool Help::init()
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

	auto item = MenuItemFont::create("Back", CC_CALLBACK_1(Help::menuHelpIsOkCallback, this));
	Menu *mm2 = Menu::create(item, NULL);
	item->setPosition(200, -100);
	this->addChild(mm2);
	return true;
}


void Help::menuHelpIsOkCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->popScene();
}