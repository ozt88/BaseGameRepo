#include "Pch.h"
#include "MapTile.h"

MapTile::MapTile()
	:m_Sprite(nullptr)
{
}

MapTile::~MapTile()
{
}

bool MapTile::init()
{
	if(!Node::init())
	{
		return false;
	}
	return true;
}
