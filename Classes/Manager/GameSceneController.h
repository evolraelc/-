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
public:
	bool init();
	bool remoteInit();
	static GameController*  create();

	bool canBuilding();
	void addBuilding(cocos2d::Vec2& Pos);
	bool canAddMan();
	bool canMan();
	void addMan(cocos2d::Vec2& Pos);
	void clickToBuild(Event *event);
	void clickToAddMan(Event *event);
	void clickToRun(Event *event);

	Game* getGameScene() { return _gameScene; }

};

#endif // !__GAME_CONTROLLER_H__

