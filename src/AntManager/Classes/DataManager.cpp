#include "Pch.h"
#include "DataManager.h"
#include "Macro.h"

DataManager* DataManager::m_Instance = nullptr;

DataManager::DataManager()
{
}

DataManager::~DataManager()
{
}

DataManager* DataManager::getInstance()
{
	if(m_Instance == nullptr)
	{
		m_Instance = new DataManager();
	}
	return m_Instance;
}

void DataManager::releaseInstance()
{
	SAFE_DELETE(m_Instance);
}


std::string DataManager::readFromFile(const std::string& filePath)
{
	std::string data;
	FILE* file = fopen(filePath.c_str(), "rb");
	if(file == NULL)
		return data;


	return data;
}

