/*
* 设计模式：单例模式
*/
#ifndef STOREHOUSE_H
#define STOREHOUSE_H

//仓库类，用于存放原料
class Storehouse {
public:
	int getnum();
	void addnum(int);
	void decreasenum(int n);
protected:
	Storehouse() { num = 0; }
	int num;
};
//存放水果的仓库
class FruitStore :public Storehouse {
public:
	~FruitStore();
	static FruitStore* GetInstance();
private:
	FruitStore() {}
	static FruitStore* fruitstore;
};
//存放肉的仓库
class MeatStore :public Storehouse {
public:
	
	~MeatStore();
	static MeatStore* GetInstance();

private:
	MeatStore() {}
	static MeatStore* meatstore;
};
//存放罐头的仓库
class CanStore  {
public:
	static CanStore* GetInstance();
	int GetLargeFruitCan();
	int GetSmallFruitCan();
	int GetLargeMeatCan();
	int GetSmallMeatCan();
	void AddCan(int, int, int, int);
	void DecreaseCan(int, int, int, int);
	void ShowAll();
private:
	CanStore() { largefruitcan = smallfruitcan = largemeatcan = smallmeatcan = 0; }
	int largefruitcan;
	int smallfruitcan;
	int largemeatcan;
	int smallmeatcan;
	static CanStore* canstore;
};
#endif
#pragma once
