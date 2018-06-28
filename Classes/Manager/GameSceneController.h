#pragma once
#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

/*作为接口接受信息并对GameScene做出改变*/
#include"Scene/GameScene.h"
#include "Scene/GameOver.h"
#include "Data/Architecture.h"
#include "Data/Player.h"
#include"cocos2d.h"
USING_NS_CC;
using namespace std;

class GameController :public Node
{
private:
	Animate *  _runAnim, *_standAnim;
	Sprite*    _enemy;
	float      ENEMY_MOVE_SPEED;
	Game *     _gameScene;
	GameOver*  _gameOver;
	Player *   _player;
	string *   _buildings[7];
	int        _price[7] =
	           { 10,10,10,10,10,1,5 };
	bool       _yes;
	int        _initmoney;
	bool       _gameover;
public:
	bool init();
	static GameController*  create();

	bool canBuilding();
	void addBuilding(cocos2d::Vec2& Pos,int kind);
	bool canAddMan();
	bool canMan();
	void clickToBuild(Event *event);
	bool onTouchBegan( Event *event);
	void update(float dt);
	void initEnemy(cocos2d::Vec2& Pos);
	void runAndStand(const Vec2& pos);
	void add(EventKeyboard::KeyCode code, Event *event);
	void money_had(int kind);

	void gameIsOver();

//	void enemy_miss();
	Game* getGameScene() { return _gameScene; };
	GameOver* creatScene() { return _gameOver; };


};

#endif // !__GAME_CONTROLLER_H__

