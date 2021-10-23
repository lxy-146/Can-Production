#pragma once
#include"factory.h"
#include"header.h"

class Order;


class Broker{
public:
	void takeorder(Order*);
	void placeorder();
	void clear();
private:
	list<Order*> orderlist;
};

class Order {
public:
	virtual void execute() = 0;
};

class KMakeOrder :public Order {
public:
	KMakeOrder(Kind* k):kind(k){}
	virtual void execute();
private:
	Kind* kind;
};

class PMakeOrder :public Order {
public:
	PMakeOrder(Packedge* p):packedge(p){}
	virtual void execute();
private:
	Packedge* packedge;
};