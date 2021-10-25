#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

//代理模式中的Subject类
class Subject {
public:
	virtual void printInfo()=0;
};

//备忘录类
class Memento {
public:
	Memento(string);
	void setState(string);
	string getState();
private:
	string state;				
	double fund;
};

//备忘录模式中的发起者
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
	string state;			//当前账本的状态信息
	double fund;			//当前公司的资金总数
};

//备忘录模式中的管理者
class Caretaker {
public:
	void addMemento(Memento*);   //添加一条记录
	Memento* getMemento();       //获取上一条记录

private:
	list<Memento*> mementos;	//存储每一条备忘录
};


//代理类（会计）
class Accountant :public Subject {
public:
	Accountant(Originator*);
	void printInfo();			//用于调用Originator的函数
	void preRequest();			//预操作
	void postRequest();			//后续操作

private:
	Originator* originator;
};