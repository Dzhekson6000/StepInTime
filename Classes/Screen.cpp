#include "Screen.h"

void Framework::Screen::initialization(cocos2d::Layer * layer, int id){
	_layer = layer;
	_id=id;
	_size = Director::getInstance()->getWinSize();
	_xPosition = 0;

	root = Layer::create();
	root->setPosition(position(0, 0));
	getScene()->addChild(root,1);
}

Point Framework::Screen::position(float x, float y)
{
	return Point(
		_size.width*(_id-1)-_xPosition
		,y);
}

void Framework::Screen::updatePosition(float xPosition)
{
	_xPosition = xPosition;
	root->setPosition(position(0, 0));
}

bool Framework::Screen::touchBegan(Touch* touch, Event* event)
{
	return true;
}

void Framework::Screen::touchMoved(Touch* touch, Event* event)
{
}

void Framework::Screen::touchEnded(Touch* touch, Event* event)
{
}