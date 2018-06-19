#pragma once
#ifndef __ROOM_H__
#define __ROOM_H__

#include "cocos2d.h"

class Room : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback

	// implement the "static create()" method manually
	CREATE_FUNC(CreateRoom);
};

#endif // !__ROOM_H__
