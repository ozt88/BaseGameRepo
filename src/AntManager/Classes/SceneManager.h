#pragma once
#define GET_SCENE_MANAGER SceneManager::getInstance

class SceneManager : public cocos2d::Object
{
public:
	static SceneManager*	getInstance();
	void					releaseInstance();
	void					changeScene(int sceneType);

private:
	SceneManager();
	virtual ~SceneManager();

private:
	static SceneManager*	m_Instance;

};

