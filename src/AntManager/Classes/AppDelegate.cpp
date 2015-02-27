#include "pch.h"
#include "AppDelegate.h"
#include "TitleScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() 
{
}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() 
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    if(!glview) {
		glview = GLView::createWithRect("My Game", Rect(0, 0, 480, 800));
        director->setOpenGLView(glview);
    }

	auto scene = TitleScene::createScene();
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() 
{
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() 
{
    Director::getInstance()->startAnimation();
}
