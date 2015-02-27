#include "Pch.h"
#include "FieldLayer.h"

USING_NS_CC;

FieldLayer::FieldLayer()
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

	return true;
}

