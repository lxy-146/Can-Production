/*
* 设计模式：观察者模式
*/
#ifndef ORDER_H
#define ORDER_H

#include "header.h"
//工具类，用于表示仓库进货的订单
class stapleorder {
public:
	stapleorder(int fnum,int mnum):_fruitnum(fnum),_meatnum(mnum){}
	void Setnum(int fnum,int mnum) {
		_fruitnum = fnum;
		_meatnum = mnum;
	}
	int GetFruitnum() {
		return _fruitnum;
	}
	int GetMeatnum() {
		return _meatnum;
	}
private:
	int _fruitnum;
	int _meatnum;
};

#endif // !ORDER_H

#pragma once
