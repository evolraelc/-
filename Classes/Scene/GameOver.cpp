#include "SimpleAudioEngine.h"
#include "GameOver.h"
USING_NS_CC;

Scene* GameOver::createScene()
{
	return GameOver::create();
}
bool GameOver::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	MenuItemFont::setFontName("Marker Felt");
	MenuItemFont::setFontSize(30);

	auto item = MenuItemFont::create("GAME OVER", [&](Ref* pSender) {  Director::getInstance()->end(); });
	Menu *mm = Menu::create(item, NULL);
	mm->setPosition(Vec2(0.5*visibleSize.width, 0.5*visibleSize.height));
	this->addChild(mm);
	return true;
}
void GameOver::menuGameIsOverCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}