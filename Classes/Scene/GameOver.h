#pragma once
#ifndef _GAMEOVER_H
#define _GAMEOVER_H


#include "cocos2d.h"
class GameOver :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuGameIsOverCallback(cocos2d::Ref* pSender);
	//  selector callbacks
	CREATE_FUNC(GameOver);
};


#endif