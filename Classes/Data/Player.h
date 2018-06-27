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
	int number;
	CC_SYNTHESIZE(int, inithp, _inithp);       //��ʼѪ��
	CC_SYNTHESIZE(int, hp, _hp);               //����Ѫ��
	CC_SYNTHESIZE(int, attack, _attack);       //������
	CC_SYNTHESIZE(cocos2d::Vec2, vel, _vel);           //��ʼ�ٶ�
	bool  _isDead = false;                     //����Ƿ�����
	bool _alreadyDead = false;                 //����Ƿ�����������
	bool _getAttack = false;


    Sprite* soldier ;
	Sprite* tank;
	Sprite * _enemy;
	cocos2d::Animate *_runAnim, *_standAnim;
	cocos2d::Label* _lblInfo;
	float ENEMY_MOVE_SPEED;
public:
	Player(){};

	virtual bool init();
	
    static Player* createPlayer(int number);

	void playerinit(int number);
	
	void Birthplace(Arch *arch);    //���������ʼλ��

	void setPlayerDead();           //������������
	
	bool isDead();                 //�ж������Ƿ�����
	

    void moveToPosition(cocos2d::Vec2 & position);   //�ƶ���ָ���ص�

    virtual void update(float dt);

	bool getAttack();

	void getRealAttack(int number);

	void DoAttack();

};


#endif // !__PLAYER_H__

