#include "Pch.h"
#include "Ant.h"

USING_NS_CC;

Ant::Ant()
{

}

Ant::~Ant()
{

}

bool Ant::init()
{
	if(!Unit::init())
	{
		return false;
	}

	return true;
}

void Ant::update(float dTime)
{

}

void Ant::move(float dTime)
{
	int moveDirection = rand() % MD_MAX;
}

void Ant::makeDirVector()
{
	m_DirVector[MD_UP] = Vec2(0, 1);
	m_DirVector[MD_UP_LEFT] = Vec2(-1, 1);
	m_DirVector[MD_UP_RIGHT] = Vec2(1, 1);
	m_DirVector[MD_LEFT] = Vec2(-1, 0);
	m_DirVector[MD_RIGHT] = Vec2(1, 0);
}
