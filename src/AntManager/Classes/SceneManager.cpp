#include "pch.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Macro.h"
#include "Type.h"

USING_NS_CC;

SceneManager* SceneManager::m_Instance = nullptr;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::getInstance()
{
	if(m_Instance == nullptr)
	{
		m_Instance = new SceneManager();
	}
	return m_Instance;
}

void SceneManager::releaseInstance()
{
	SAFE_DELETE(m_Instance);
}


void SceneManager::changeScene(int sceneType)
{
	Scene* scene = nullptr;
	switch(sceneType)
	{
		case SceneType::ST_TITLE:
			scene = TitleScene::createScene();
			break;
		case SceneType::ST_GAME:
			scene = GameScene::createScene();
			break;
		default:
			break;
	}

	if(scene != nullptr)
	{
		Director::getInstance()->replaceScene(scene);
	}
}
