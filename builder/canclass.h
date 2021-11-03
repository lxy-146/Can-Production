#pragma once
/*
* 实现模式：适配器模式，策略模式
*/
#include"header.h"
#include"can.h"
class can {
protected:
	int number;//罐头编号
	double cost;//罐头成本
	double time;//罐头生产周期
public:
	can();
	double returncost();
	int returnnumber();//返回罐头编号
};




class can_large_vegetable :public can {
public:
	can_large_vegetable();
};
class can_small_vegetable:public can {
public:
	can_small_vegetable();
};
class can_large_meat:public can {
public:
	can_large_meat();
};
class can_small_meat:public can {
public:
	can_small_meat();
};
//适配器模式，strategy模式
class can_set_adapter {
private:
	Can *tool;
public:
	can_set_adapter();
	can_set_adapter(Can *temp);
	~can_set_adapter();
	double getbigprice();
	double getsmallprice();
	int protime();//获取某种罐头的生产周期
};