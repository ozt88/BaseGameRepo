#include "Pch.h"
#include "GameUILayer.h"

USING_NS_CC;

GameUILayer::GameUILayer()
{
}

GameUILayer::~GameUILayer()
{
}

bool GameUILayer::init()
{
	if(!Layer::init())
	{
		return false;
	}

	return true;
}
