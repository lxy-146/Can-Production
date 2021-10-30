/*
* 设计模式：单例模式
*/
#ifndef STOREHOUSE_H
#define STOREHOUSE_H

//仓库类，用于存放原料
class Storehouse {
public:
	Storehouse() { num = 0; }
	int getnum();
	void addnum(int);
	void decreasenum(int n);
protected:
	int num;
};
//存放水果的仓库
class FruitStore :public Storehouse {
public:
	FruitStore() {}
	~FruitStore();
	static FruitStore* GetInstance();
private:
	static FruitStore* fruitstore;
};
//存放肉的仓库
class MeatStore :public Storehouse {
public:
	MeatStore(){}
	~MeatStore();
	static MeatStore* GetInstance();

private:
	static MeatStore* meatstore;
};
#endif
#pragma once
