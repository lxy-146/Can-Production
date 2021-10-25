#pragma once
#include<iostream>
using namespace std;

//请求类
class Request {
public:
	Request(int num, string name);
	int getLevel();
private:
	int level;						//请求的等级
	string content;					//请求内容
	static int counter;				//用于给请求类型标号（在打印请求选项时中用到）
};


//抽象处理者
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

//具体处理者Leader
class Leader : public Handler {
public:
	void handleRequest(int);
};

//具体处理者Manager
class Manager : public Handler {
public:
	void handleRequest(int);
};

//具体处理者Boss
class Boss : public Handler {
public:
	void handleRequest(int);
};