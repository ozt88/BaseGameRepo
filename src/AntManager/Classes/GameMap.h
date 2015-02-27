#pragma once

class MapModel;
class MapTile;
class GameMap : public cocos2d::Node
{
public:
	GameMap();
	virtual ~GameMap();
	virtual bool init();

	CREATE_FUNC(GameMap);
private:
	void		makeTiles();
private:
	std::vector<MapTile*>	m_Tiles;
};