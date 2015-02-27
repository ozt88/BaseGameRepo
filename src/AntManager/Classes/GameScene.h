#pragma once

class GameScene : public cocos2d::Layer
{
public:
	GameScene();
	virtual ~GameScene();
	static cocos2d::Scene*	createScene();
	virtual bool			init();
	
	CREATE_FUNC(GameScene);

public:
	enum LayerZOrder
	{
		LZO_NONE,
		LZO_FIELD,
		LZO_UI,
		LZO_MAX,
	};

private:

private:
	cocos2d::Layer*			m_FieldLayer;
	cocos2d::Layer*			m_UILayer;
};

