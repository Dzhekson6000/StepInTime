#pragma once
#ifndef AUTHORIZATION_SCENE_H
#define AUTHORIZATION_SCENE_H

#include "cocos2d.h"

USING_NS_CC;

class AuthorizationScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	
	CREATE_FUNC(AuthorizationScene);
};


#endif // AUTHORIZATION_SCENE_H