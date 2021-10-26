#ifndef ORDER_H
#define ORDER_H

#include "header.h"

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
