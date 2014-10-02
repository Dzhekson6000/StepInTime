#pragma once
#include "cocos2d.h"
USING_NS_CC;

namespace Framework{
	class Screen
	{
	protected:
		cocos2d::Layer * _layer;
		float _xPosition;
		int _id;
		Size _size;

		Layer*root;
		Point position(float x, float y);
	public:
		void initialization(cocos2d::Layer * layer, int id);
		virtual void draw(){}
		virtual void update(float dt){}
		cocos2d::Layer * getScene(){ return _layer;}

		void updatePosition(float xPosition);

		virtual bool touchBegan(Touch* touch, Event* event);
		virtual void touchMoved(Touch* touch, Event* event);
		virtual void touchEnded(Touch* touch, Event* event);

	};
}