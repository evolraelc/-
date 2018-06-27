#include "cocos2d.h"
#include "Player.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include<string>
#include<iostream>
using namespace std;
using namespace cocostudio::timeline;
bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}

 Player* Player::createPlayer(int number)
{
	Player *sprite = new Player();
	if (sprite && sprite->init())
	{
		sprite->autorelease();
		sprite->playerinit(number);
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

 void Player::playerinit(int number)
 {
	 this->number = number;
	 if (number == 1) {
		 auto soldier = Sprite::create("soldier.png");
		 inithp = hp = 100;
		 attack = 30;
	 }
	 else if (number == 2) {
		 auto tank = Sprite::create("tank.png");
		 inithp = hp = 200;
		 attack = 50;
	 }
	 else if (number == 3) {
		 auto tank = Sprite::create("dog.png");
		 inithp = hp = 50;
		 attack = 20;
	 }
 
 }

void Player::Birthplace(Arch *arch)    //设置人物初始位置
{
	this->setPosition(arch->getPosition() + cocos2d::Vec2(0, arch->getContentSize().height / 2));
	this->setVisible(true);
}

void Player::setPlayerDead()           //设置人物死亡
{
	_isDead = true;
}

bool Player::isDead()                 //判断人物是否死亡
{
	return _isDead;
}

void Player::moveToPosition(cocos2d::Vec2 & pos)
{
	float distance = _enemy->getPosition().getDistance(pos);
	auto moveTo =cocos2d::MoveTo::create(distance / ENEMY_MOVE_SPEED, pos);
	auto standCall = cocos2d::CallFunc::create([=] {
		_enemy->stopAllActions();
		_enemy->runAction(cocos2d::RepeatForever::create(_standAnim));
	});

	_enemy->stopAllActions();
	_enemy->setFlippedX(pos.x < _enemy->getPosition().x);
	_enemy->runAction(cocos2d::RepeatForever::create(_runAnim));
	_enemy->runAction(cocos2d::Sequence::createWithTwoActions(moveTo, standCall));
	/*cocos2d::Vec2  initPos = this->getPosition();
	float x = position.x - initPos.x;
	float y = position.y - initPos.y;
	vel.x = x / 10;
	vel.y = y / 10;
	this->setVisible(true);
	this->unscheduleUpdate();*/
	this->scheduleUpdate();

}

void Player::update(float dt)
{
	static float curTime = 0;
	curTime += dt;
	if (curTime > dt * 2.f)
	{
		curTime -= dt * 2.f;
	}
}



void Player::getRealAttack(int number)
{
	if (number == 1)
	{
		this->hp = hp - 30;
	}
	else if (number == 2)
	{
		this->hp = hp - 50;
	}
	else if (number == 3)
	{
		this->hp = hp - 20;
	}
}