
#ifndef _START_SCENE_H
#define _START_SCENE_H
#include "cocos2d.h"
class Start:public cocos2d::Scene
{
private:
	int* a;
	//TMXTiledMap *_tileMap;
public:

	static cocos2d::Scene* createScene();
	virtual bool init();

	//  selector callbacks
	void menuStartIsOkCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(Start);
};
#endif