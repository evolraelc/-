#ifndef __ARCHITECTURE_H__
#define __ARCHITECTURE_H__

#include"cocos2d.h"
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
	int kind;
public:

	Arch() { inithp = 100; };
	/*static Arch* create(const std::string& filename)
	{
		Arch *sprite = new Arch();
		if (sprite && sprite->initWithFile(filename))
		{
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}*/
	static Arch* createWithArchTypes(cocos2d::Vec2& Pos, int kind)
	{
		Arch *sprite = new Arch();
		Sprite *basement = Sprite::create("basement.png");
		Sprite *powerplant = Sprite::create("powerplant,png");
        Sprite *minefield = Sprite::create("minefield,png");
        Sprite *barracks = Sprite::create("barracks.png");
        Sprite *warfactory = Sprite::create("warfactory.png");
		const char *ArchFrameName = "basement.png";
		switch (kind)
		{
		case 1:
			basement->setPosition(Pos);
			sprite->inithp = 100;
			break;
		case 2:
			
			powerplant->setPosition(Pos);
			sprite->inithp = 100;
			break;
		case 3:
			
			minefield->setPosition(Pos);
			sprite->inithp = 100;
			break;
		case 4:
			
			barracks->setPosition(Pos);
			sprite->inithp = 100;
			break;
		case 5:
			
			warfactory->setPosition(Pos);
			sprite->inithp = 100;
			break;
		};

		if (sprite && sprite->initWithSpriteFrameName(ArchFrameName))
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