#include "ChainOfResponsibility.h"
using namespace std;

//Request类的构造函数
Request::Request(int num, string name) {
		counter++;
		level = num;
		content = name;
		cout << counter << "." << content << endl;		//创建Request对象的同时打印并标号
}
int Request::getLevel() {
		return this->level;
}
int Request::counter = 0;		//初始化请求种类为0

Handler::Handler(){
	nextHandler = nullptr;
}
void Handler::setNextHandler(Handler* nextHandler) {
	this->nextHandler = nextHandler;
}
Handler* Handler::getNextHandler() {
	return nextHandler;
}
void Handler::handleRequest(int) {};


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
