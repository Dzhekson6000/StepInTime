#include "AuthorizationScene.h"



Scene* AuthorizationScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AuthorizationScene::create();

	scene->addChild(layer);

	return scene;
}

bool AuthorizationScene::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

	
	return true;
}


