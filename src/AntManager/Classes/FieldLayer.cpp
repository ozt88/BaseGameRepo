#include "Pch.h"
#include "FieldLayer.h"
#include "GameMap.h"

USING_NS_CC;

FieldLayer::FieldLayer()
	:m_GameMap(nullptr)
{
}

FieldLayer::~FieldLayer()
{
}

bool FieldLayer::init()
{
	if(!Layer::init())
	{
		return false;
	}
	m_GameMap = GameMap::create();
	addChild(m_GameMap);
	return true;
}

