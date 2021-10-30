#pragma once
/*
* ʵ��ģʽ������ģʽ
*/
#include"factory.h"
#include"header.h"

class Order;

//�������order����
class Broker{
public:
	void takeorder(Order*);
	void placeorder();
	void clear();
private:
	list<Order*> orderlist;
};
//������
class Order {
public:
	virtual void execute() = 0;
};
//��������д����������
class KMakeOrder :public Order {
public:
	KMakeOrder(Kind* k):kind(k){}
	virtual void execute();
private:
	Kind* kind;
};
//�԰�װ���д����������
class PMakeOrder :public Order {
public:
	PMakeOrder(Package* p):package(p){}
	virtual void execute();
private:
	Package* package;
};