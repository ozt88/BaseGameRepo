#include "pch.h"
#include "GameScene.h"
#include "FieldLayer.h"
#include "GameUILayer.h"

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
	m_FieldLayer = FieldLayer::create();
	m_UILayer = GameUILayer::create();
	addChild(m_FieldLayer, LZO_FIELD);
	addChild(m_UILayer, LZO_UI);

	return true;
}


