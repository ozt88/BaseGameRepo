#pragma once

class GameMap : public cocos2d::Node
{
public:
	GameMap();
	virtual ~GameMap();
	virtual bool init();

	CREATE_FUNC(GameMap);
private:
};