#include "pch.h"
#include "GameScene.h"
#include "FieldLayer.h"
#include "GameUILayer.h"
#include "Define.h"

USING_NS_CC;

GameScene::GameScene()
	:m_FieldLayer(nullptr), m_UILayer(nullptr)
{
}

GameScene::~GameScene()
{
}

cocos2d::Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if(!Layer::init())
	{
		return false;
	}
	Point fieldPosition(FIELD_RECT.origin);
	m_FieldLayer = FieldLayer::create();
	m_UILayer = GameUILayer::create();
	m_FieldLayer->setPosition(fieldPosition);

	makeBackground();
	addChild(m_FieldLayer, LZO_FIELD);
	addChild(m_UILayer, LZO_UI);

	return true;
}

void GameScene::makeBackground()
{
	auto winSize = Director::getInstance()->getWinSize();
	auto bgSprite = Sprite::create("Background.png");
	bgSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
	addChild(bgSprite, -1);
}


