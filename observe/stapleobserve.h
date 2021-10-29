#ifndef STAPLEOBSERVE_H
#define STAPLEOBSERVE_H

#include"header.h"
#include"stapleorder.h"
#include"storehouse.h"

class Observe {
public:
	virtual void update(stapleorder*) = 0;
};
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

void OrderSubject::Attach(Observe* addone) {
	cout << "An observe attached to ordersubject" << endl;
	_observe_list.push_back(addone);
}

void OrderSubject::Dettach(Observe* delone) {
	_observe_list.remove(delone);
}

void OrderSubject::Notify(stapleorder* order) {
	for (auto i : _observe_list)
		i->update(order);
}

void OrderSubject::SetOrder(int fnum, int mnum) {
	stapleorder* order = new stapleorder(fnum, mnum);
	Notify(order);
}




class FruitObserve :public Observe {
public:
	virtual void update(stapleorder*);
};

void FruitObserve::update(stapleorder* order) {
	Storehouse* storehouse=FruitStore::GetInstance();
	storehouse->addnum(order->GetFruitnum());
}


class MeatObserve :public Observe {
public:
	virtual void update(stapleorder*);
};

void MeatObserve::update(stapleorder* order) {
	Storehouse* storehouse = MeatStore::GetInstance();
	storehouse->addnum(order->GetMeatnum());
}

#endif // !STAPLEOBSERVE_H

#pragma once
