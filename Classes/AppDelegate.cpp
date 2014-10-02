#include "AppDelegate.h"
#include "MainScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        //glview = GLView::createWithFullScreen("Step in time");
		glview = GLView::create("Step in time");
        director->setOpenGLView(glview);
    }

	glview->setDesignResolutionSize(1366, 768, kResolutionShowAll);

    director->setDisplayStats(false);

    director->setAnimationInterval(1.0 / 10);
	

    auto scene = MainScene::createScene();

	Director::getInstance()->pushScene(scene);
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
