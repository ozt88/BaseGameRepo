#pragma once

class ResourceManager : public cocos2d::Object
{
public:
	static ResourceManager*	getInstance();
	void					releaseInstance();
	cocos2d::Sprite*		getTileSprite(int tileType);
private:
	ResourceManager();
	virtual ~ResourceManager();

private:
	static ResourceManager* m_Instance;
	cocos2d::Sprite*		m_MapSprites;
};