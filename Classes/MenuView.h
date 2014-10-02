#ifndef MENU_VIEW_H_
#define MENU_VIEW_H_

#include "cocos2d.h"
USING_NS_CC;

class MenuView
{
	Size _size;
	std::vector<std::string> _menuLabel;
	std::vector<Label*> _menuList;
	Sprite* _fon;
	int _idSelect;
public:
	int getMenuN();
	void initialization(cocos2d::Layer * layer);
	void onSelect(int id);
	boolean isSelectedMenu(float y);
	int selectMenuItem(float x);
};

#endif /* MENU_VIEW_H_ */