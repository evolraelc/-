#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "Architecture.h"
#include<string>
#include<iostream>
using namespace std;

class Player : public cocos2d::Sprite
{
private:
	Sprite* soldier ;
	Sprite* tank;
	CC_SYNTHESIZE(int, inithp, _inithp);       //初始血量
	CC_SYNTHESIZE(int, hp, _hp);               //现在血量
	CC_SYNTHESIZE(cocos2d::Vec2, vel, _vel);           //初始速度
	bool  _isDead = false;                     //玩家是否死亡
	bool _alreadyDead = false;                 //玩家是否真正的死亡
public:
	Player()
	{

	};

	void initPlayer(int inithp);

    static Player* createWithSpriteFrameName(const char * SpriteFrameName);
	
	void Birthplace(Arch *arch);    //设置人物初始位置

	void setPlayerDead();           //设置人物死亡
	
	bool isDead();                 //判断人物是否死亡
	

    void moveToPosition(cocos2d::Vec2 & position);

    virtual void update(float dt);

};


#endif // !__PLAYER_H__

