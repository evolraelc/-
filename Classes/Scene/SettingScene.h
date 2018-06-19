#ifndef _SETTINGSCENE_H
#define _SETTINGSCENE_H
#include "cocos2d.h"
class Setting :public cocos2d::Layer
{
	bool isEffect;
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void OnEnter();
	virtual void OnEnterTransitionDidFinish();
	virtual void OnExit();
	virtual void OnExitTransitionDidStart();
	virtual void cleanup();
	//  selector callbacks
	void menuSoundToggleCallback(cocos2d::Ref* pSender);
	void menuMusicToggleCallback(cocos2d::Ref* pSender);
	void menuSettingIsOkCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(Setting);
};



#endif