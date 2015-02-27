#pragma once
#define GET_DATA_MANAGER DataManager::getInstance

class DataManager : public cocos2d::Object
{
public:
	static DataManager*	getInstance();
	void				releaseInstance();
	std::string			readFromFile(const std::string& filePath);

private:
	DataManager();
	virtual ~DataManager();

private:
	static DataManager*	m_Instance;
};

