/*
* BlackBoard.h - Definition
*/


#include "BlackBoard.h"

BlackBoard::BlackBoard()
{
}

BlackBoard::~BlackBoard()
{
}

/*
* Function:在黑板中设置bool值，可添加额外条件
*/

void BlackBoard::setValue(std::string key, bool value)
{
	mDatas.emplace(key, value);
}

void BlackBoard::setValue(std::string key, bool value, float expiredTime, bool expiredValue)
{
	setValue(key, value);
	mTimers.emplace_back(BlackBoardTimer{ expiredTime,key,expiredValue });
}

/*
* Function:在黑板中获取bool值
*/
bool BlackBoard::getBool(std::string key)
{
	auto& value = mDatas.at(key);
	return value;
}

/*
* Function:展示黑板中所写的数据
*/
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
/*
* Function:解析黑板中获得的bool值
*/
std::string BlackBoard::parseBool(bool value)
{
	if (value == true)
	{
		return "YES";
	}
	else return "NO";
}


/*
* Function:更新黑板中的数据
*/
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