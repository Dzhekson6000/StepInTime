#pragma once
#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__


#include "Framework.h"
#include "MenuView.h"

USING_NS_CC;

class MainScene : public cocos2d::Layer
{
	EventListenerTouchOneByOne* _touchListener;
	Size _size;

	std::vector<Framework::Screen*> _screenList;

	Sprite* _fon;
	MenuView* _menu;

	float _xPosition;

	boolean _moved;
	float _xMoved;

	void addScreen(int id, Screen*screen);
	void updatePosition();
	void moveEndClick();
	int getScreenN();
	void goToScreen(int n);
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void onDraw();
	virtual bool touchBegan(Touch* touch, Event* event);
	virtual void touchMoved(Touch* touch, Event* event);
	virtual void touchEnded(Touch* touch, Event* event);

	void update(float dt);

	CREATE_FUNC(MainScene);
};

#endif // __MAIN_SCENE_H__