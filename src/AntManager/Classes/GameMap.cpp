#include "Pch.h"
#include "GameMap.h"
#include "MapModel.h"
#include "MapTile.h"
#include "Define.h"

USING_NS_CC;

GameMap::GameMap()
{
	m_MapModel = new MapModel();
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
	m_MapModel->initFromFile(MAP_DATA_01);
	makeTiles();
	return true;
}

void GameMap::makeTiles()
{
	int width = m_MapModel->getWidth();
	int height = m_MapModel->getHeight();
	int checkIdx = 0;
	Point setPos;
	m_Tiles.resize(width*height);
	for(int yIdx = 0; yIdx < height; ++yIdx)
	{
		for(int xIdx = 0; xIdx < width; ++xIdx)
		{
			checkIdx = xIdx + yIdx * width;
			setPos.x = xIdx * TILE_SIZE_WIDTH;
			setPos.y = (height - yIdx) * TILE_SIZE_HEIGHT;
			m_Tiles[checkIdx] = MapTile::create();
			m_Tiles[checkIdx]->initTile(m_MapModel->getData(checkIdx));
			m_Tiles[checkIdx]->setPosition(setPos);
			addChild(m_Tiles[checkIdx]);
		}
	}
}
