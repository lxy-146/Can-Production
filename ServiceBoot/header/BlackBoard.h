
#ifndef BLAKC_BOARD_H
#define BLAKC_BOARD_H

#pragma once
#include <map>
#include <list>
#include <string>
#include <iostream>

//黑板类
class BlackBoard
{
private:
	//黑板计时器
	struct BlackBoardTimer {
		float timer;
		std::string key;
		bool value;
	};
protected:
	std::map<std::string, bool> mDatas;
	std::list<BlackBoardTimer> mTimers;
public:
	BlackBoard();
	~BlackBoard();
	//设置数据
	void setValue(std::string key, bool value);
	void setValue(std::string key, bool value, float expiredTime, bool expiredValue);
	void setValue(std::string key, int value);
	void setValue(std::string key, int value, float expiredTime, int expiredValue);
	void setValue(std::string key, float value);
	void setValue(std::string key, float value, float expiredTime, float expiredValue);
	void setValue(std::string key, std::string value);
	//访问数据
	int getInt(std::string key);
	float getFloat(std::string key);
	bool getBool(std::string key);
	std::string getString(std::string key);

	void showBlackBoard();
	std::string parseBool(bool value);
	//更新时间
	void update(float dt);
};


#endif // !BLAKC_BOARD_H
#pragma once