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
const int spriteTag[ITEM_AMOUNT + 1]{ 0 };
const string imageAdress[ITEM_AMOUNT + 1]
{
	"test.png"
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

public:
	bool init();
	bool getIsChosen() { return _isChosen; };
	void setIsChosen(bool a) { _isChosen = a; };
	bool clickDownToChoose(Event* event);

	
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

	MapLayer* getMapLayer() { return _mapLayer; };
	MenuLayer* getMenuLayer() { return _menuLayer; };
	static Game* createScene();
	CREATE_FUNC(Game);
	friend class GameController;

};





#endif	//__GAMESCENE_H__

