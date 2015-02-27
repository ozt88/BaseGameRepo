#pragma once

//실제 게임이 벌어지는 Field의 Layer
class GameMap;
class FieldLayer : public cocos2d::Layer
{
public:
	FieldLayer();
	virtual ~FieldLayer();
	virtual bool	init();

	CREATE_FUNC(FieldLayer);
private:

private:
	GameMap*		m_GameMap;
};