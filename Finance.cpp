#include<iostream>
#include<string>
#include<list>
#include"Finance.h"
using namespace std;

Memento::Memento(string state) {
	this->state = state;
}
void Memento::setState(string state) {
	this->state = state;
}
string Memento::getState() {
	return state;
}


Originator::Originator(double fund) {
	this->fund = fund;
}
void Originator::setState(string state) {
	cout << "账本状态更新..." << endl;
	this->state = state;
}
string Originator::getState() {
	return state;
}
void Originator::printInfo() {
	cout << "账本当前状态: " << this->getState()<<"  ";
	cout << "资金总额: " << this->getFund() << endl;
}
Memento* Originator::createMemento() {
	return new Memento(state);
}
void Originator::restoreMemento(Memento* m) {
	cout << "账本恢复至上一状态" << endl;
	this->setState(m->getState());
	this->printInfo();
}
double Originator::getFund() {
	return this->fund;
}
void Originator::setFund(int operation, double num) {
	if (operation == 0) {
		cout << "资金数额变动..." << endl;
		this->fund -= num;
	}
	else if (operation == 1) {
		cout << "资金数额变动..." << endl;
		this->fund += num;
	}
	else cout << "operation error" << endl;
}


void Caretaker::addMemento(Memento* m) {
	mementos.push_back(m);
}
Memento* Caretaker::getMemento() {
	Memento* m = mementos.back();
	mementos.pop_back();			  //删除容器最后一个元素
	return m;						  //最后一个元素的引用
} 


Accountant::Accountant(Originator* org){
	this->originator = org;
}
void Accountant::printInfo() {
	preRequest();
	originator->printInfo();
	postRequest();
}
void Accountant::preRequest() {
	cout << "会计正在查询..." << endl;
}
void Accountant::postRequest() {
	cout << "会计查询结束" << endl;

}