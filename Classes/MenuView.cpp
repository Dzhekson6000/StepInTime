#include "MenuView.h"

void MenuView::initialization(cocos2d::Layer * layer)
{
	_size = Director::getInstance()->getWinSize();
	
	_menuLabel.push_back("Home");
	_menuLabel.push_back("Playground projects");
	_menuLabel.push_back("Directory");
	_menuLabel.push_back("Chat");
	_menuLabel.push_back("Forum");
	_menuLabel.push_back("Storage");

	_idSelect = 1; //выбран по умолчанию

	//создём фон
	_fon = Sprite::create("img/ScreenMenu.png");
	_fon->setScaleX(_size.width/_fon->getContentSize().width);
	_fon->setScaleY(_size.width/_fon->getContentSize().width);
	_fon->setPosition(Point(_size.width/2, _size.height- (_fon->getContentSize().height*_fon->getScaleY()/2) ));
	layer->addChild(_fon, 0);

	//создаём надписи
	std::vector<std::string>::iterator menuLabelIterator;
	menuLabelIterator = _menuLabel.begin();
	
	float manuW = _size.width / _menuLabel.size();
	int n = 1;

	_menuList.clear();
	while (menuLabelIterator != _menuLabel.end())
	{
		Label* text = Label::createWithTTF(*menuLabelIterator, "fonts/menuFont.otf", 26);
		if(n == _idSelect)
		{
			text->setColor(Color3B::RED);
		}else{
			text->setColor(Color3B::GREEN);
		}

		
		text->setPosition(Point( (manuW*n)-(manuW/2), _size.height- 16 ));
		layer->addChild(text, 1);
		_menuList.push_back(text);
		++n;
		++menuLabelIterator;
    }
	
}

void MenuView::onSelect(int id){
	_idSelect = id;

	int n = 1;

	std::vector<Label*>::iterator menuListIterator;
	menuListIterator = _menuList.begin();
	while (menuListIterator != _menuList.end())
	{
		if(n == _idSelect)
		{
			(*menuListIterator)->setColor(Color3B::RED);
		}else{
			(*menuListIterator)->setColor(Color3B::GREEN);
		}
		++n;
		++menuListIterator;
	}
}

int MenuView::getMenuN()
{
	return _menuLabel.size();
}

boolean MenuView::isSelectedMenu(float y)
{
	if(y > _size.height-(_fon->getContentSize().height*_fon->getScaleY()))
	{
		return true;
	}
	return false;
}

int MenuView::selectMenuItem(float x)
{
	float manuW = _size.width / _menuLabel.size();
	return floor(x/manuW)+1;
}