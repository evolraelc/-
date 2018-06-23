#pragma once
#ifndef __CREATEROOM_H__
#define __CREATEROOM_H__

#include "cocos2d.h"

; class CreateRoom : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(CreateRoom);
};
#endif // !__CREATEROOM_H__

