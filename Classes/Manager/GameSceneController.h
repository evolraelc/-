#pragma once
#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

/*作为接口接受信息并对GameScene做出改变*/
#include"Scene/GameScene.h"
#include "Data/Architecture.h"
#include "Data/Player.h"
#include"cocos2d.h"
USING_NS_CC;
using namespace std;
class GameController :public Node
{
private:
	Game * _gameScene;
	Player * _player;
	string *buildings[7];
public:
	bool init();
	static GameController*  create();

	bool canBuilding();
	void addBuilding(cocos2d::Vec2& Pos,int kind);
	bool canAddMan();
	bool canMan();
	void playerMove(cocos2d::Vec2& Pos);
	void addMan(cocos2d::Vec2& Pos,int kind);
	void clickToBuild(Event *event);
	void clickToAddMan(Event *event);
	void clickToRun(Event *event);

	Game* getGameScene() { return _gameScene; }

};

#endif // !__GAME_CONTROLLER_H__

