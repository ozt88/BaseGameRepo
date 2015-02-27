#include "Pch.h"
#include "ResourceManager.h"
#include "Macro.h"

USING_NS_CC;

ResourceManager* ResourceManager::m_Instance = nullptr;

ResourceManager::ResourceManager()
{
	m_MapSprites = Sprite::create("tile.png");
	m_MapSprites->retain();
}

ResourceManager::~ResourceManager()
{
	m_MapSprites->release();
}

ResourceManager* ResourceManager::getInstance()
{
	if(m_Instance == nullptr)
	{
		m_Instance = new ResourceManager();
	}
	return m_Instance;
}

void ResourceManager::releaseInstance()
{
	SAFE_DELETE(m_Instance);
}

