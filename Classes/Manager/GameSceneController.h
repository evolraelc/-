#pragma once
#ifndef __GAMESCNEN_CONTROLLER_H__
#define __GAMESCENE_CONTROLLER_H__

/*作为接口接受信息并对GameScene做出改变*/
#include"Scene/GameScene.h"
#include"cocos2d.h"
USING_NS_CC;
using namespace std;

class GameSceneController :public Node
{
private:
	Game * _gameScene;

public:
	bool init();

	Game* getGameScene() { return _gameScene; }

	CREATE_FUNC(GameSceneController);
};

#endif // !__GAMESCNEN_CONTROLLER_H__

