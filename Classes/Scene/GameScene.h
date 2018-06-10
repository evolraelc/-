#pragma once
#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__
#include "cocos2d.h"
USING_NS_CC;
/*这个场景为游戏场景，分为三层：地图，菜单层，文本层*/


class Game:public Layer
{
private:
	TMXTiledMap * _tileMap;
	Sprite *player;
public:
	virtual bool init();
	static Scene* createScece();
	CREATE_FUNC(Game);

};





#endif	//__GAMESCENE_H__

