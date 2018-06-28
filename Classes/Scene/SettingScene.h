#ifndef _SETTINGSCENE_H
#define _SETTINGSCENE_H
#include <iostream>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
class Setting :public cocos2d::Layer
{
	bool isEffect;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void onEnter();
	void menuSettingIsOkCallback(Ref* pSender);
	void onEnterTransitionDidFinish();
	void onExit();
	void onExitTransitionDidStart();
	void cleanup();
	void menuSoundToggleCallback(Ref* pSender);
	void menuMusicToggleCallback(Ref* pSender);
	CREATE_FUNC(Setting);
};



#endif