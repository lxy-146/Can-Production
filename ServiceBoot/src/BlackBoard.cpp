
#include "BlackBoard.h"

BlackBoard::BlackBoard()
{
}

BlackBoard::~BlackBoard()
{
}

void BlackBoard::setValue(std::string key, int value)
{
	mDatas.emplace(key, value);
}

void BlackBoard::setValue(std::string key, int value, float expiredTime, int expiredValue)
{}

void BlackBoard::setValue(std::string key, float value)
{}

void BlackBoard::setValue(std::string key, float value, float expiredTime, float expiredValue)
{}

void BlackBoard::setValue(std::string key, std::string value)
{}

void BlackBoard::setValue(std::string key, bool value)
{
	mDatas.emplace(key, value);
}

void BlackBoard::setValue(std::string key, bool value, float expiredTime, bool expiredValue)
{
	setValue(key, value);
	mTimers.emplace_back(BlackBoardTimer{ expiredTime,key,expiredValue });
}


int BlackBoard::getInt(std::string key)
{
	auto& value = mDatas.at(key);
	return value;
}


float BlackBoard::getFloat(std::string key)
{
	auto& value = mDatas.at(key);
	return value;
}

bool BlackBoard::getBool(std::string key)
{
	auto& value = mDatas.at(key);
	return value;
}

std::string BlackBoard::getString(std::string key)
{
	auto& value = mDatas.at(key);
	std::string s;
	return s;
}

void BlackBoard::update(float dt)
{
	auto itr = mTimers.begin();
	while (itr != mTimers.end()) {
		itr->timer -= dt;
		if (itr->timer <= 0.0f) {
			mDatas[itr->key] = itr->value;
			itr = mTimers.erase(itr);
		}
		else {
			++itr;
		}
	}
}

void BlackBoard::showBlackBoard()
{
	std::map<std::string, bool> ::iterator iter;
	iter = mDatas.begin();
	while (iter != mDatas.end())
	{
		std::cout << iter->first << "  :  " << parseBool(getBool(iter->first)) << std::endl;
		iter++;
	}
}

std::string BlackBoard::parseBool(bool value)
{
	if (value == true)
	{
		return "YES";
	}
	else return "NO";
}