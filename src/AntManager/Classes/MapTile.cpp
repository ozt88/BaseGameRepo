#include "Pch.h"
#include "MapTile.h"
#include "Define.h"
USING_NS_CC;

MapTile::MapTile()
	:m_Sprite(nullptr)
{
	m_Sprite = Sprite::create("tile.png");
	addChild(m_Sprite);
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

void MapTile::initTile(int tileId)
{
	Size spriteSize = m_Sprite->getContentSize();
	int xIdx = tileId % TILE_PNG_WIDTH;
	int yIdx = tileId / TILE_PNG_WIDTH;
	Point tilePos(xIdx * TILE_SIZE_WIDTH, yIdx * TILE_SIZE_HEIGHT);
	Rect tileRect(tilePos.x, tilePos.y, TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT);

	m_Sprite->setTextureRect(tileRect);
	m_Sprite->setAnchorPoint(Point::ZERO);
}
