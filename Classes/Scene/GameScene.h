#pragma once
#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"
#include"ui/CocosGUI.h"
USING_NS_CC;
using namespace std;
enum
{
	ITEM_AMOUNT = 0
};
enum
{
	MAP_LAYER_TAG,
	MENU_LAYER_TAG
};
const string itemImageAdress[ITEM_AMOUNT + 1][3]
{
	"hello.png","hello.png","hello.png"
};
/*这个场景为游戏场景，分为三层：地图，菜单层，文本层*/




/*class MapLayer :public Layer
{
private:
	TMXTiledMap * _map;
	TMXLayer * _collidable;
public:
	bool init();
	Vec2 tileCoordFromPosition(Vec2 position);
};


class MenuLayer :public Menu
{
private:
	vector<Button*> constructButton;

};*/




class Game:public Scene
{
private:
	TMXTiledMap * _tileMap;
	TMXLayer * _collidable;
	//static auto visibleSize = Director::getInstance()->getVisibleSize();
	//static Vec2 origin = Director::getInstance()->getVisibleOrigin();
public:
	virtual bool init();
	void initMap();
	//void initMenu();
	static Game* createScene();
	CREATE_FUNC(Game);
	void onEnter();
	void onExit();

	bool clickDown(Event *event);
	void clickMove(Event *event);
	void clickUp(Event *event);
};





#endif	//__GAMESCENE_H__

