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
	bg->setPosition(Vec2( visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bg);

	MenuItemFont::setFontName("Marker Felt");
	MenuItemFont::setFontSize(60);

	auto item = MenuItemFont::create("Back",
		[&](Ref* pSender) {Director::getInstance()->popScene(); });
	item->setPosition(Vec2(0.8*visibleSize.width, 0.2*visibleSize.height));

	Menu *mm = Menu::create(item, NULL);
	mm->alignItemsVertically();
	this->addChild(mm);

	return true;
}
