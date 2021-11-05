/*
* 设计模式：观察者模式
*/
#ifndef STAPLEOBSERVE_H
#define STAPLEOBSERVE_H

#include"header.h"
#include"stapleorder.h"
#include"storehouse.h"
//观察者类，抽象类
class Observe {
public:
	virtual void update(stapleorder*) = 0;
};
//用于对观察者进行操作的类
class OrderSubject {
public:
	OrderSubject() { _observe_list.clear(); }
	void Attach(Observe*);
	void Dettach(Observe*);
	void Notify(stapleorder*);
	void SetOrder(int fnum, int mnum);
private:
	list<Observe*> _observe_list;
};
//对于水果的观察者
class FruitObserve :public Observe {
public:
	virtual void update(stapleorder*);
};
//对于肉类的观察者
class MeatObserve :public Observe {
public:
	virtual void update(stapleorder*);
};
/*
* 函数：OrderSubject::Attach
* 参数：Observe* addone
* 功能：将一个观察者连接到操作器上
*/
void OrderSubject::Attach(Observe* addone) {
	cout << "OrderSubject:Attach:An observe attached to ordersubject" << endl;
	_observe_list.push_back(addone);
}
/*
* 函数：OrderSubject::Dettach
* 参数：Observe* delone
* 功能：将一个观察者从操作器上移除
*/
void OrderSubject::Dettach(Observe* delone) {
	_observe_list.remove(delone);
}
/*
* 函数：OrderSubject::Notify
* 参数：stapleorder* order
* 功能：发生了变动，传来了订单，所有的观察者都根据订单进行相应操作
*/
void OrderSubject::Notify(stapleorder* order) {
	for (auto i : _observe_list)
		i->update(order);
}
/*
* 函数：OrderSubject::SetOrder
* 参数：int fnum, int mnum
* 功能：建立订单，同时调用Notify执行观察者
*/
void OrderSubject::SetOrder(int fnum, int mnum) {
	stapleorder* order = new stapleorder(fnum, mnum);
	Notify(order);
}
/*
* 函数：FruitObserve::update
* 参数：stapleorder* order
* 功能：根据订单内容对于仓库货物进行增加
*/
void FruitObserve::update(stapleorder* order) {
	Storehouse* storehouse = FruitStore::GetInstance();
	cout << "FruitObserve:update:fruitobserve updated" << endl;
	storehouse->addnum(order->GetFruitnum());
}
/*
* 函数：MeatObserve::update
* 参数：stapleorder* order
* 功能：根据订单内容对于仓库货物进行增加
*/
void MeatObserve::update(stapleorder* order) {
	Storehouse* storehouse = MeatStore::GetInstance();
	cout << "MeatObserve:update:meatobserve updated" << endl;
	storehouse->addnum(order->GetMeatnum());
}
#endif // !STAPLEOBSERVE_H

#pragma once
