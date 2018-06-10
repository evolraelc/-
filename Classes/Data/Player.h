#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include"cocos2d.h"
#include<string>
#include<iostream>
using namespace std;
using namespace cocos2d;
/*Player类，继承自Node，记录玩家数据*/

class Player :public cocos2d::Node
{
private:
	string _playerName;			//玩家姓名
public:
	bool init(string &name)
	static Player* create(string &name);
	void setPlayerName(string &name);
	string getPlayerName();
};


bool Player::init(string &name)
{
	if (!Node::init())
	{
		return false;
	}
	this->Player::setPlayerName(name);
	return true;
}


Player* Player::create(string &name)
{
	auto pl = new Player;
	if (pl&&pl->init(name))
	{
		return pl;
	}
	else
	{
		return nullptr;
	}
}


void Player::setPlayerName(string &name)
{
	_playerName = name;
}


string Player::getPlayerName()
{
	return _playerName;
}




#endif // !__PLAYER_H__

