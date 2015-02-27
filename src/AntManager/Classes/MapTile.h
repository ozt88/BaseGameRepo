#pragma once
class MapTile : public cocos2d::Node
{
public:
	MapTile();
	virtual ~MapTile();
	virtual bool init();

	CREATE_FUNC(MapTile);
private:

private:
	cocos2d::Sprite*	m_Sprite;
};