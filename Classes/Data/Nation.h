#pragma once
#ifndef __NATION_H__
#define __NATION_H__

#include"cocos2d.h"
#include<string>

enum 
	{
	INIT_MONEY = 100
	};
using namespace std;
/*游戏中每位玩家所代表的国家，继承自Node*/

class Nation :public cocos2d::Node
{
private:
	string _playerName;
	string _nation;

	int _money;
	/*
	vection<Solder> _enemy;
	vection<Building> _build;
	*/

	bool isALive;
public:
	static Nation* create(string& playerName,string &nation);
	bool init(string &playerName, string &nation);

	void setPlayerName(string& playerName) { _playerName = playerName; };
	string getPlayerName() { return _playerName; };

	void setNation(string& nation) { _nation = nation; };
	string getNation() { return _nation; };

	void setMoney(int money) { _money = money; };
	int getMoney() { return _money; };

};

Nation* Nation::create(string &playerName, string &nation)
{
	Nation *na = new Nation;
	if (na&&na->Nation::init(playerName, nation))
	{
		return na;
	}
	else
	{
		return nullptr;
	}
}


bool Nation::init(string &playerName, string &nation)
{
	if (!Node::init())
	{
		return false;
	}
	this->Nation::setPlayerName(playerName);
	this->Nation::setNation(nation);
	this->Nation::setMoney(INIT_MONEY);
	return true;
}


#endif // !__NATION_H__
