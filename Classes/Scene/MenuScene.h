#pragma once
#ifndef _MENU_SCENE_H
#define _MENU_SCENE_H

#include "cocos2d.h"

class Menu_S : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	//  selector callbacks
    void menuHelpCallback(cocos2d::Ref* pSender);
	void menuStartCallback(cocos2d::Ref* pSender);
	void menuSettingCallback(cocos2d::Ref* pSender);
	void menuGetCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(Menu_S);
};


#endif

