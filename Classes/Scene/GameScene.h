#pragma once
#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"
#include"ui/CocosGUI.h"
USING_NS_CC;
using namespace std;
enum
{
	BUTTON_AMOUNT = 0
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
public:
	virtual bool init();
	void initMap();
	void initMenu();
	static Game* createScece();
	CREATE_FUNC(Game);
};





#endif	//__GAMESCENE_H__

