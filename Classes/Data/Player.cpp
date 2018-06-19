#include "cocos2d.h"
#include "Player.h"
#include<string>
#include<iostream>
using namespace std;

void Player::initPlayer(int inithp)
{
	this->inithp = 100;
};

 Player* Player::createWithSpriteFrameName(const char * SpriteFrameName)
{
	Player *sprite = new Player();
	if (sprite && sprite->initWithSpriteFrameName(SpriteFrameName))
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

void Player::moveToPosition(cocos2d::Vec2 & position)
{
	cocos2d::Vec2  initPos = this->getPosition();
	float x = position.x - initPos.x;
	float y = position.y - initPos.y;
	vel.x = x / 10;
	vel.y = y / 10;
	this->setVisible(true);
	this->unscheduleUpdate();
	this->scheduleUpdate();

}

void Player::update(float dt)
{
	this->setPosition(cocos2d::Vec2(this->getPosition()+vel*dt));
	if (dt == 10.0f)
	{
		this->unscheduleUpdate();
		this->removeFromParent();
	}
}