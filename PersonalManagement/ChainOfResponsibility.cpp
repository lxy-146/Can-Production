/*
*ChainOfResponsibility.h-defination
*/

#include "ChainOfResponsibility.h"
using namespace std;

/*
*函数：Request::Request
*参数：int num, string name
*功能：Request构造函数
*/
Request::Request(int num, string name) {
	counter++;
	level = num;
	content = name;
	cout << counter << "." << content << endl;		//创建Request对象的同时打印并标号
}

/*
*函数：Request::getLevel
*参数：null
*功能：返回Request的等级
*/
int Request::getLevel() {
	return this->level;
}
int Request::counter = 0;		//初始化请求种类为0

/*
*函数：Handler::Handler
*参数：null
*功能：Handler构造函数
*/
Handler::Handler() {
	nextHandler = nullptr;
}

/*
*函数：Handler::setNextHandler
*参数：Handler* nextHandler
*功能：设置当前Handler的下一级Handler
*/
void Handler::setNextHandler(Handler* nextHandler) {
	this->nextHandler = nextHandler;
}

/*
*函数：Handler::getNextHandler
*参数：null
*功能：返回当前Handler的下一级Handler
*/
Handler* Handler::getNextHandler() {
	return nextHandler;
}


void Handler::handleRequest(int) {};

/*
*函数：Leader::handleRequest
*参数：int level
*功能：Leader处理员工请求
*/
void Leader::handleRequest(int level) {
	if (level < 4) {
		cout << "请求已由Leader处理！" << endl;
	}
	else {
		if (this->getNextHandler() != nullptr) {
			this->getNextHandler()->handleRequest(level);
		}
		else cout << "请求过分,无法处理！" << endl;
	}
}

/*
*函数：Manager::handleRequest
*参数：int level
*功能：Manager处理员工请求
*/
void Manager::handleRequest(int level) {
	if (level >= 4 && level < 7) {
		cout << "请求已由Manager处理！" << endl;
	}
	else {
		if (this->getNextHandler() != nullptr) {
			this->getNextHandler()->handleRequest(level);
		}
		else cout << "请求过分,无法处理！" << endl;
	}
}


/*
*函数：Boss::handleRequest
*参数：int level
*功能：Boss处理员工请求
*/
void Boss::handleRequest(int level) {
	if (level >= 7 && level < 10) {
		cout << "请求已由Boss处理！" << endl;
	}
	else {
		if (this->getNextHandler() != nullptr) {
			this->getNextHandler()->handleRequest(level);
		}
		else cout << "请求无人处理！" << endl;
	}
}
