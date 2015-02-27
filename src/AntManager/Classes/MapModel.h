#pragma once
#include "json.h"

class MapModel : public cocos2d::Object
{
public:
	MapModel();
	virtual	~MapModel();
	void		initFromFile(const std::string& filePath);
	int			getData(int idx);

private:
	void		fromJson(const Json::Value& value);
	
private:
	std::vector<int>	m_MapData;
	CC_SYNTHESIZE_READONLY(int, m_Width, Width);
	CC_SYNTHESIZE_READONLY(int, m_Height, Height);
};