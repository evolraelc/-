#pragma once
#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

/*作为接口接受信息并对GameScene做出改变*/
#include"Scene/GameScene.h"
#include"cocos2d.h"
USING_NS_CC;
using namespace std;

class GameController :public Node
{
private:
	Game * _gameScene;
	Player* _player;
public:
	bool locationInit();
	bool remoteInit();

	bool canBuilding();
	bool addBuilding();
	bool canMan();
	bool addMan();

	bool clickToChoose(Event *event);
	void clickToBuild(Event *event);
	void clickToRun(Event *event);

	Game* getGameScene() { return _gameScene; }

	CREATE_FUNC(GameController);
};

#endif // !__GAME_CONTROLLER_H__

