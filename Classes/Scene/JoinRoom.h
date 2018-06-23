#pragma once
#ifndef __JOINROOM_H__
#define __JOINROOM_H__

#include "cocos2d.h"

class JoinRoom : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback;

	// implement the "static create()" method manually
	CREATE_FUNC(JoinRoom);
};
#endif // !__JOINROOM_H__

