#pragma once
#ifndef _HELP_SCENE_H
#define _HELP_SCENE_H


#include "cocos2d.h"
class Help :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	//  selector callbacks
	CREATE_FUNC(Help);
};



#endif