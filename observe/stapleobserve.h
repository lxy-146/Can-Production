/*
* ���ģʽ���۲���ģʽ
*/
#ifndef STAPLEOBSERVE_H
#define STAPLEOBSERVE_H

#include"header.h"
#include"stapleorder.h"
#include"storehouse.h"
//�۲����࣬������
class Observe {
public:
	virtual void update(stapleorder*) = 0;
};
//���ڶԹ۲��߽��в�������
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
//����ˮ���Ĺ۲���
class FruitObserve :public Observe {
public:
	virtual void update(stapleorder*);
};
//��������Ĺ۲���
class MeatObserve :public Observe {
public:
	virtual void update(stapleorder*);
};
/*
* ������OrderSubject::Attach
* ������Observe* addone
* ���ܣ���һ���۲������ӵ���������
*/
void OrderSubject::Attach(Observe* addone) {
	cout << "OrderSubject:Attach:An observe attached to ordersubject" << endl;
	_observe_list.push_back(addone);
}
/*
* ������OrderSubject::Dettach
* ������Observe* delone
* ���ܣ���һ���۲��ߴӲ��������Ƴ�
*/
void OrderSubject::Dettach(Observe* delone) {
	_observe_list.remove(delone);
}
/*
* ������OrderSubject::Notify
* ������stapleorder* order
* ���ܣ������˱䶯�������˶��������еĹ۲��߶����ݶ���������Ӧ����
*/
void OrderSubject::Notify(stapleorder* order) {
	for (auto i : _observe_list)
		i->update(order);
}
/*
* ������OrderSubject::SetOrder
* ������int fnum, int mnum
* ���ܣ�����������ͬʱ����Notifyִ�й۲���
*/
void OrderSubject::SetOrder(int fnum, int mnum) {
	stapleorder* order = new stapleorder(fnum, mnum);
	Notify(order);
}
/*
* ������FruitObserve::update
* ������stapleorder* order
* ���ܣ����ݶ������ݶ��ڲֿ�����������
*/
void FruitObserve::update(stapleorder* order) {
	Storehouse* storehouse = FruitStore::GetInstance();
	cout << "FruitObserve:update:fruitobserve updated" << endl;
	storehouse->addnum(order->GetFruitnum());
}
/*
* ������MeatObserve::update
* ������stapleorder* order
* ���ܣ����ݶ������ݶ��ڲֿ�����������
*/
void MeatObserve::update(stapleorder* order) {
	Storehouse* storehouse = MeatStore::GetInstance();
	cout << "MeatObserve:update:meatobserve updated" << endl;
	storehouse->addnum(order->GetMeatnum());
}
#endif // !STAPLEOBSERVE_H

#pragma once
