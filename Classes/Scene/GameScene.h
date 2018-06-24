#pragma once
#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"
#include"ui/CocosGUI.h"
USING_NS_CC;
using namespace std;
const int  ITEM_AMOUNT = 8;
enum
{
	MAP_LAYER_TAG,
	MENU_LAYER_TAG
};
enum ITEM_TAG
{
	basement = 1,
	dianchang,
	kuangchang,
	bingying,
	chechang,
	zaobing,
	zaoche,
};
const string imageAdress[ITEM_AMOUNT]
{
"basement.png",
"powerplant.png",
"minefield.png",
"barracks.png",
"warfactory.png",
"Item_zaobing.png",
"Item_zaoche.png",
"Item_dog.png"

};
/*这个场景为游戏场景，分为三层：地图，菜单层，文本层*/
class GameController;


class MapLayer :public Layer
{
private:
	TMXTiledMap * _map;
	TMXLayer * _collidable;
	bool _isDrag;			//鼠标是否在拖动
	Vec2 _posBeginDrag;
public:
	bool init();

	bool clickDownToDrag(Event* event);
	void clickMoveToDrag(Event *event);
	void clickUpToDrag(Event *event);

	void onEnter();
	void onExit();
	CREATE_FUNC(MapLayer);

	friend class Game;
	friend class GameController;
};


class MenuLayer :public Layer
{
private:
	bool _isChosen;
	int _kind;

	bool _isAdding;

public:
	bool init();
	bool getIsChosen() { return _isChosen; };
	void setIsChosen(bool a) { _isChosen = a; };
	void callBack(Ref* pSender);
	
	CREATE_FUNC(MenuLayer);
	friend class Game;
	friend class GameController;

};




class Game:public Scene
{
private:
	MapLayer * _mapLayer;
	MenuLayer *_menuLayer;

	//static auto visibleSize = Director::getInstance()->getVisibleSize();
	//static Vec2 origin = Director::getInstance()->getVisibleOrigin();
public:
	virtual bool init();
	void initMapLayer();
	void initMenuLayer();
	static Game* Game::create();

	MapLayer* getMapLayer() { return _mapLayer; };
	MenuLayer* getMenuLayer() { return _menuLayer; };
	static Game* createScene();
	friend class GameController;

};





#endif	//__GAMESCENE_H__

