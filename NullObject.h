#ifndef NULLOBJECT_H
#define NULLOBJECT_H
#include<iostream>
#include<string>
using namespace std;

//创建一个抽象类AbstractBuyer表示采购商。
class AbstractBuyer
{
public:
	AbstractBuyer() {};
	virtual ~AbstractBuyer() {};
	virtual bool isNull() = 0;
	virtual string getName() = 0;

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
};

string BuyerFactory::name[4] = { "WalMart","Carrefour","Hualian","Darunfa" };

AbstractBuyer* BuyerFactory::getBuyer(string tname)
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (name[i] == tname)
		{
			return (AbstractBuyer*)new RealBuyer(tname);
		}
	}
	return (AbstractBuyer*)new NullBuyer();
}

#endif

#pragma once