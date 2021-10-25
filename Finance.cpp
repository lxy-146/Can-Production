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
	cout << "�˱�״̬����..." << endl;
	this->state = state;
}
string Originator::getState() {
	return state;
}
void Originator::printInfo() {
	cout << "�˱���ǰ״̬: " << this->getState()<<"  ";
	cout << "�ʽ��ܶ�: " << this->getFund() << endl;
}
Memento* Originator::createMemento() {
	return new Memento(state);
}
void Originator::restoreMemento(Memento* m) {
	cout << "�˱��ָ�����һ״̬" << endl;
	this->setState(m->getState());
	this->printInfo();
}
double Originator::getFund() {
	return this->fund;
}
void Originator::setFund(int operation, double num) {
	if (operation == 0) {
		cout << "�ʽ�����䶯..." << endl;
		this->fund -= num;
	}
	else if (operation == 1) {
		cout << "�ʽ�����䶯..." << endl;
		this->fund += num;
	}
	else cout << "operation error" << endl;
}


void Caretaker::addMemento(Memento* m) {
	mementos.push_back(m);
}
Memento* Caretaker::getMemento() {
	Memento* m = mementos.back();
	mementos.pop_back();			  //ɾ���������һ��Ԫ��
	return m;						  //���һ��Ԫ�ص�����
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
	cout << "������ڲ�ѯ..." << endl;
}
void Accountant::postRequest() {
	cout << "��Ʋ�ѯ����" << endl;

}