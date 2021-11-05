/*
*Finance.h-defination
*/

#include"Finance.h"

/*
*������Memento::Memento
*������string state, double fund
*���ܣ�Memento���캯��
*/
Memento::Memento(string state, double fund) {
	this->state = state;
	this->fund = fund;
}

/*
*������Memento::setState
*������string state
*���ܣ����ñ���¼״̬��Ϣ
*/
void Memento::setState(string state) {
	this->state = state;
}

/*
*������Memento::getState
*������null
*���ܣ����ر���¼״̬��Ϣ
*/
string Memento::getState() {
	return state;
}

/*
*������Originator::Originator
*������double fund
*���ܣ�Originator���캯�����趨��ҵ�ʽ�����
*/
Originator::Originator(double fund) {
	this->fund = fund;
}

/*
*������Originator::setState
*������string state
*���ܣ����õ�ǰ�˱�״̬
*/
void Originator::setState(string state) {
	cout << "Originator:setState:�����˱�״̬��Ϣ" << endl;
	this->state = state;
}

/*
*������Originator::getState
*������null
*���ܣ����ص�ǰ�˱�״̬
*/
string Originator::getState() {
	return state;
}

/*
*������Originator::printInfo
*������null
*���ܣ���ӡ��ǰ�˱���Ϣ
*/
void Originator::printInfo() {
	cout << "Originator:printInfo:��ʾ�˱�״̬��Ϣ" << endl;
	cout << "�˱���ǰ״̬: " << this->getState() << "  ";
	cout << "�ʽ��ܶ�: " << this->getFund() << endl;
}

/*
*������Originator::createMemento
*������null
*���ܣ����˱���ǰ״̬��Ϣ����Ϊһ������
*/
Memento* Originator::createMemento() {
	cout << "Originator:createMemento:����һ����¼���浱ǰ״̬��Ϣ"<<endl;
	return new Memento(state, fund);
}

/*
*������Originator::restoreMemento
*������Memento* m
*���ܣ��ָ���һ�μ�¼���˱�״̬��Ϣ
*/
void Originator::restoreMemento(Memento* m) {
	cout << "Originator:restoreMemento:�˱��ָ�����һ״̬" << endl;
	this->setState(m->getState());
	this->printInfo();
}

/*
*������Originator::getFund
*������null
*���ܣ������˱���ǰ���ʽ�����
*/
double Originator::getFund() {
	return this->fund;
}

/*
*������Originator::setFund
*������int operation, double num
*���ܣ��޸��˱����ʽ�����
*/
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

/*
*������Caretaker::addMemento
*������Memento* m
*���ܣ�����¼������һ����¼
*/
void Caretaker::addMemento(Memento* m) {
	cout << "Caretaker:addMemento:��Ӽ�¼������¼��"<<endl;
	mementos.push_back(m);
}

/*
*������Caretaker::addMemento
*������null
*���ܣ����ر���¼�е����µ�һ����¼
*/
Memento* Caretaker::getMemento() {
	Memento* m = mementos.back();
	mementos.pop_back();			  //ɾ���������һ��Ԫ��
	return m;						  //���һ��Ԫ�ص�����
}

/*
*������Accountant::Accountant
*������Originator* org
*���ܣ�Accountant���캯�������ô�����Ĵ������
*/
Accountant::Accountant(Originator* org) {
	this->originator = org;
}

/*
*������Accountant::printInfo
*������null
*���ܣ������ѯ�˱���ǰ״̬��Ϣ
*/
void Accountant::printInfo() {
	cout << "Accountant:printInfo:���ô�������printInfo����" << endl;
	preRequest();
	originator->printInfo();
	postRequest();
}

/*
*������Accountant::preRequest
*������null
*���ܣ������ѯԤ����
*/
void Accountant::preRequest() {
	cout << "������ڲ�ѯ..." << endl;
}

/*
*������Accountant::postRequest
*������null
*���ܣ������ѯ��������
*/
void Accountant::postRequest() {
	cout << "��Ʋ�ѯ����" << endl;

}