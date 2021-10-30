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
* Function:�ںڰ�������boolֵ������Ӷ�������
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
* Function:�ںڰ��л�ȡboolֵ
*/
bool BlackBoard::getBool(std::string key)
{
	auto& value = mDatas.at(key);
	return value;
}

/*
* Function:չʾ�ڰ�����д������
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
* Function:�����ڰ��л�õ�boolֵ
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
* Function:���ºڰ��е�����
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