#pragma once
#include<iostream>
using namespace std;

//������
class Request {
public:
	Request(int num, string name);
	int getLevel();
private:
	int level;						//����ĵȼ�
	string content;					//��������
	static int counter;				//���ڸ��������ͱ�ţ��ڴ�ӡ����ѡ��ʱ���õ���
};


//��������
class Handler {
public:
	Handler();
	virtual ~Handler() {};
	void setNextHandler(Handler*);
	Handler* getNextHandler();
	virtual void handleRequest(int);
private:
	Handler* nextHandler;
};

//���崦����Leader
class Leader : public Handler {
public:
	void handleRequest(int);
};

//���崦����Manager
class Manager : public Handler {
public:
	void handleRequest(int);
};

//���崦����Boss
class Boss : public Handler {
public:
	void handleRequest(int);
};