#include "Pch.h"
#include "GameMap.h"

USING_NS_CC;

GameMap::GameMap()
{
}

GameMap::~GameMap()
{
}

bool GameMap::init()
{
	if(!Node::init())
	{
		return false;
	}

	return true;
}
