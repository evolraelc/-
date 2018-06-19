#include"CreateRoom.h"
#include "ui/CocosGUI.h"
#include"cocos2d.h"
#include<iostream>;

using namespace std;
using namespace cocos2d::ui;
USING_NS_CC;
Scene* CreateRoom::createScene()
{
	return CreateRoom::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MenuScene.cpp\n");
}

bool CreateRoom::init()
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

	auto textField = TextField::create("", "Arial", 30);
	textField->setPosition(Vec2(0.5*visibleSize.width, 0.5*visibleSize.height));
	this->addChild(textField);

	MenuItemFont::setFontName("Marker Felt");
	MenuItemFont::setFontSize(60);
	auto item = MenuItemFont::create("Back",
		[&](Ref* pSender) {Director::getInstance()->popScene(); });

	item->setPosition(Vec2(0.8*visibleSize.width, 0.8*visibleSize.height) );
	Menu *mm = Menu::create(item, NULL);
	this->addChild(mm);



	return true;
}

void CreateRoom::menuGetCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->popScene();
}

