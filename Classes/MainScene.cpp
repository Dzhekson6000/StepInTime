#include "MainScene.h"

Scene* MainScene::createScene()
{

	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init()
{
	if ( !Layer::init() )
    {
        return false;
    }


	_size = Director::getInstance()->getWinSize();
	_xPosition = 0;
	_xMoved = 0;

	_touchListener = EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(MainScene::touchBegan,this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(MainScene::touchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(MainScene::touchEnded,this);
	getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 100);

	addScreen(1, new MainScreen);
	addScreen(2, new MainScreen);

	_fon = Sprite::create("img/ScreenFon.png");
	_fon->setScaleX(_size.width/_fon->getContentSize().width);
	_fon->setScaleY(_size.height/_fon->getContentSize().height);
	_fon->setPosition(Point(_size.width/2, _size.height/2));
	this->addChild(_fon,0);

	_menu = new MenuView;
	_menu->initialization(this);


	TextFieldTTF * tf = TextFieldTTF::textFieldWithPlaceHolder("click for input",
        "fonts/menuFont.otf",
        26);
	tf->setPosition(Point(300,300));
	this->addChild(tf, 10);
	tf->attachWithIME();

	//this->schedule(schedule_selector(MainScene::update),0.05f);

	return true;
}

bool MainScene::touchBegan(Touch *touch, Event *event)
{
	return true;
}

void MainScene::touchMoved(Touch* touch, Event* event)
{
	if(touch->getLocation().x < 0 || touch->getLocation().x > _size.width)return;
	
	if( (touch->getLocation().x < 300 || touch->getLocation().x >  _size.width-300) && !_moved)
	{
		_moved = true;
		_xMoved = touch->getLocation().x;
	}

	if(_moved)
	{
		_xPosition -= touch->getLocation().x - _xMoved;
		_xMoved = touch->getLocation().x;
	}
	updatePosition();
}

void MainScene::touchEnded(Touch* touch, Event* event)
{
	if(_moved)moveEndClick();
	if(_menu->isSelectedMenu(touch->getLocation().y) )
	{
		goToScreen(_menu->selectMenuItem(touch->getLocation().x));
	}

	
}

void MainScene::update(float dt)
{

}

void MainScene::updatePosition()
{
	std::vector<Screen*>::iterator screenListIterator;
	screenListIterator = _screenList.begin();
	while (screenListIterator != _screenList.end())
	{
		(*screenListIterator)->updatePosition(_xPosition);
		++screenListIterator;
	}
}

void MainScene::addScreen(int id, Screen*screen)
{
	screen->initialization(this, id);
	screen->draw();
	_screenList.push_back(screen);
}

int MainScene::getScreenN()
{
	return floor(_xPosition / _size.width) + 1;
}

void MainScene::moveEndClick()
{
	int n = getScreenN();
	//остаток до следующего скрина
	float remain = _size.width*n - _xPosition;

	if(remain < _size.width/2)
	{//вправо
		if( (int)_screenList.size() > n )
		{
			_xPosition = _size.width*n;
		} else {
			_xPosition = _size.width*((int)_screenList.size()-1);
		}
	}else{//влево
		if(n<1)
		{
			_xPosition = _size.width*n;
		} else {
			_xPosition = _size.width*(n-1);
		}
		
	}

	updatePosition();

	n = getScreenN();
	_menu->onSelect(n);
	_moved = false;
}

void MainScene::goToScreen(int n)
{
	_menu->onSelect(n);
	_xPosition = _size.width * (n-1);
	updatePosition();
}