/*
* 实现模式：空对象模式、工厂模式
*/
#ifndef NULLOBJECT_H
#define NULLOBJECT_H
#include<iostream>
#include<string>
using namespace std;

//创建一个抽象类AbstractBuyer表示采购商。
class AbstractBuyer
{
public:
	//虚函数，待两类采购商对象继承实现
	AbstractBuyer() {};
	virtual ~AbstractBuyer() {};
	/*
	* 函数：isNull
	* 功能：确定采购商是否在我们的清单上
	*/
	virtual bool isNull() = 0;
	/*
	* 函数：getName
	* 功能：返回采购商的名称，若不在清单上，返回提示信息
	*/
	virtual string getName() = 0;
	//构造函数、析构函数，判断是否为空的采购商

protected:
	string name;
};

//创建扩展了抽象类AbstractBuyer的实体类RealBuyer。
class RealBuyer :AbstractBuyer
{
public:
	RealBuyer(string tname) { name = tname; };
	~RealBuyer() {};
	bool isNull() { return false; };
	string getName() { return name; };
};

//创建扩展了抽象类AbstractBuyer的空类NullBuyer。
class NullBuyer :AbstractBuyer
{
public:
	NullBuyer() {};
	~NullBuyer() {};
	bool isNull() { return true; };
	string getName() { return "It is NOT on our buyer list!"; };
};

//创建BuyerFactory类，用来获取实体类或空类的实例
class BuyerFactory
{
public:
	BuyerFactory() {};
	~BuyerFactory() {};
	static string name[4];
	static AbstractBuyer* getBuyer(string tname);
	//采购商清单的构造
};

string BuyerFactory::name[4] = { "WalMart","Carrefour","Hualian","Darunfa" };

/*
* 函数：BuyerFactory::getBuyer
* 功能：工厂模式构造若干个采购商，若不在清单上构造为NullBuyer，否则为RealBuyer
*/
AbstractBuyer* BuyerFactory::getBuyer(string tname)
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (name[i] == tname)
		{
			//若tname在采购商清单上则返回RealBuyer
			return (AbstractBuyer*)new RealBuyer(tname);
		}
	}
	return (AbstractBuyer*)new NullBuyer();
	//使用工厂模式，由采购商清单得到一列采购商
}

#endif

#pragma once