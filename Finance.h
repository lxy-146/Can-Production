#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

//����ģʽ�е�Subject��
class Subject {
public:
	virtual void printInfo()=0;
};

//����¼��
class Memento {
public:
	Memento(string);
	void setState(string);
	string getState();
private:
	string state;				
	double fund;
};

//����¼ģʽ�еķ�����
class Originator:public Subject{
public:
	Originator(double);
	void setState(string);
	string getState();
	void printInfo();
	Memento* createMemento();
	void restoreMemento(Memento*);
	double getFund();
	void setFund(int, double);
private:
	string state;			//��ǰ�˱���״̬��Ϣ
	double fund;			//��ǰ��˾���ʽ�����
};

//����¼ģʽ�еĹ�����
class Caretaker {
public:
	void addMemento(Memento*);   //���һ����¼
	Memento* getMemento();       //��ȡ��һ����¼

private:
	list<Memento*> mementos;	//�洢ÿһ������¼
};


//�����ࣨ��ƣ�
class Accountant :public Subject {
public:
	Accountant(Originator*);
	void printInfo();			//���ڵ���Originator�ĺ���
	void preRequest();			//Ԥ����
	void postRequest();			//��������

private:
	Originator* originator;
};