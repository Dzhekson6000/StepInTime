#include "MainScreen.h"


void MainScreen::draw()
{
	auto sprite = Sprite::create("img/ScreenProjectFon.png");
	sprite->setScaleX(_size.width/sprite->getContentSize().width);
	sprite->setScaleY(_size.height/sprite->getContentSize().height);
	sprite->setPosition(Point(_size.width/2, _size.height/2));
	root->addChild(sprite, 0);
}