#pragma once
/*
* 实现模式：命令模式
*/
#include"factory.h"
#include"header.h"

class Order;

//用来存放order的类
class Broker{
public:
	void takeorder(Order*);
	void placeorder();
	void undo();
	void clear();
private:
	list<Order*> orderlist;
	bool isexecute;
};
//命令类
class Order {
public:
	virtual void execute() = 0;
	virtual void unexecute() = 0;
};
//对种类进行处理的命令类
class KMakeOrder :public Order {
public:
	KMakeOrder(Kind* k):kind(k){}
	virtual void execute();
	virtual void unexecute();
private:
	Kind* kind;
};
//对包装进行处理的命令类
class PMakeOrder :public Order {
public:
	PMakeOrder(Package* p):package(p){}
	virtual void unexecute();
	virtual void execute();
private:
	Package* package;
};