#ifndef __ARCHITECTURE_H__
#define __ARCHITECTURE_H__

#include"cocos2d.h"
#include"Nation.h"
#include<string>
#include<iostream>
using namespace std;

class Arch :public cocos2d::Sprite
{
private:
		CC_SYNTHESIZE(int, inithp, _inithp);       //初始血量
	    CC_SYNTHESIZE(int, hp, _hp);               //现在血量
		bool  _isDead = false;                     //基地是否爆炸
		bool _alreadyDead = false;                 //基地是否真正的爆炸
public:
	Arch();
	Arch(int inithp)
	{
		this->inithp = 100;
	}
	static Arch* createWithSpriteFrameName(const std::string& filename)
	{
		Arch *sprite = new Arch();
		if (sprite && sprite->initWithSpriteFrameName(filename))
		{
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}
	void setPlayerDead()           //设置阵营爆炸
	{
		_isDead = true;
	}

	bool isDead()                 //判断阵地是否真的爆炸
	{
		return _isDead;
	}

};




















#endif