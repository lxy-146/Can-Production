#ifndef NULLOBJECT_H
#define NULLOBJECT_H
#include<iostream>
#include<string>
using namespace std;

//����һ��������AbstractBuyer��ʾ�ɹ��̡�
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

//������չ�˳�����AbstractBuyer��ʵ����RealBuyer��
class RealBuyer :AbstractBuyer
{
public:
	RealBuyer(string tname) { name = tname; };
	~RealBuyer() {};
	bool isNull() { return false; };
	string getName() { return name; };
};

//������չ�˳�����AbstractBuyer�Ŀ���NullBuyer��
class NullBuyer :AbstractBuyer
{
public:
	NullBuyer() {};
	~NullBuyer() {};
	bool isNull() { return true; };
	string getName() { return "It is NOT on our buyer list!"; };
};

//����BuyerFactory�࣬������ȡʵ���������ʵ��
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