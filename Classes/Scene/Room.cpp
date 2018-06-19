#include"Room.h"
#include"Createroom.h"
#include"JoinRoom.h"
USING_NS_CC;
Scene* Room::createScene()
{
	return Room::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MenuScene.cpp\n");
}

bool Room::init()
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

	auto item1 = MenuItemFont::MenuItemFont::create("CreateRoom",
		[&](Ref *pSender) {auto cr = CreateRoom::createScene();
		Director::getInstance()->pushScene(cr); }); 

	auto item2 = MenuItemFont::create("JoinRoom",
		[&](Ref *pSender) {auto jo = JoinRoom::createScene();

		Director::getInstance()->pushScene(jo); });
	auto item3 = MenuItemFont::create("Back", 
		[&](Ref* pSender) {Director::getInstance()->popScene(); }
		);
	Menu *mm = Menu::create(item1, item2, item3, NULL);
	mm->alignItemsVertically();
	this->addChild(mm);

	return true;
}


