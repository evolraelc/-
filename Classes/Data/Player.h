#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "Architecture.h"
#include<string>
#include<iostream>
using namespace std;
/*Player类，继承自Node，记录玩家数据*/

class Player: public cocos2d::Sprite
{
private:
	CC_SYNTHESIZE(int, inithp, _inithp);       //初始血量
	CC_SYNTHESIZE(int, hp, _hp);               //现在血量
	CC_SYNTHESIZE(float, vel, _vel);           //初始速度
	bool  _isDead = false;                     //玩家是否死亡
	bool _alreadyDead = false;                 //玩家是否真正的死亡
public:
	Player();
	Player(int inithp)
	{
		this->inithp = 100;
	}
	void setSpeed(float speed)
	{
		vel = speed;
	}

	float getSpeed()
	{
		return vel;
	}

	static Player* create(const std::string& filename)
	{
		Player *sprite = new Player();
		if (sprite && sprite->initWithFile(filename))
		{
			sprite->autorelease();
/*			sprite->setVisible(false);

			auto body = PhysicsBody::createBox(sprite->getContentSize());

			body->setCategoryBitmask(0x01);
			body->setCollisionBitmask(0x02);
			body->setContactTestBitmask(0x01);

			sprite->setPhysicsBody(body);
*/
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}
/*	void Birthplace(Arch *Arch)
	{
		this->setPosition(arch->getPosition() + cocos2d::Vec2(0, arch->getContentSize().height / 2));
		this->setVisible(true);
	}
*/
	void setPlayerDead()           //设置人物死亡
	{
		_isDead = true;
	}

	bool isDead()                 //判断人物是否死亡
	{
		return _isDead;
	}




};


#endif // !__PLAYER_H__

