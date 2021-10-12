#ifndef STOREHOUSE_H
#define STOREHOUSE_H

/// <summary>
/// 仓库类，用于存放所有的水果、肉类，函数实现放在对应cpp中
/// </summary>
class Storehouse {
public:
	virtual int getnum() = 0;
	virtual void addnum(int) = 0;
	virtual void decreasenum(int n) = 0;
	Storehouse(){}
};

class FruitStore :public Storehouse {
public:
	FruitStore():fruitnum(0) {}
	~FruitStore();
	static FruitStore* GetInstance();
	virtual int getnum();
	virtual void addnum(int n);
	virtual void decreasenum(int n);
private:
	int fruitnum;
	static FruitStore* fruitstore;
};

class MeatStore :public Storehouse {
public:
	MeatStore():meatnum(0){}
	~MeatStore();
	static MeatStore* GetInstance();
	virtual int getnum();
	virtual void addnum(int n);
	virtual void decreasenum(int n);
private:
	int meatnum;
	static MeatStore* meatstore;
};

#endif
#pragma once
