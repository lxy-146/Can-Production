
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
{
	setValue(key, value);
	mTimers.emplace_back(BlackBoardTimer{ expiredTime,key,expiredValue });
}

void BlackBoard::setValue(std::string key, float value)
{
	mDatas.emplace(key, value);
}

void BlackBoard::setValue(std::string key, float value, float expiredTime, float expiredValue)
{
	setValue(key, value);
	mTimers.emplace_back(BlackBoardTimer{ expiredTime,key,expiredValue });
}

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
	return std::any_cast<int>(value);
}

void BlackBoard::setValue(std::string key, std::string value)
{
	mDatas.emplace(key, value);
}

float BlackBoard::getFloat(std::string key)
{
	auto& value = mDatas.at(key);
	return std::any_cast<float>(value);
}

bool BlackBoard::getBool(std::string key)
{
	auto& value = mDatas.at(key);
	return std::any_cast<bool>(value);
}

std::string BlackBoard::getString(std::string key)
{
	auto& value = mDatas.at(key);
	return std::any_cast<std::string>(value);
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
	std::map<std::string, std::any> ::iterator iter;
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

//int main()
//{
//	BlackBoard blockBoard;
//	blockBoard.setValue("NO.1 Meat Productor needs to be repaired", true);
//	blockBoard.setValue("NO.2 Meat Productor needs to be repaired", false);
//	blockBoard.setValue("NO.1 Vegetable Productor needs to be repaired", false);
//	blockBoard.setValue("NO.2 Vegetable Productor needs to be repaired", true);
//
//	blockBoard.showBlackBoard();
//	system("pause");
//}
