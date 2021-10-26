#include "ChainOfResponsibility.h"
using namespace std;

//Request��Ĺ��캯��
Request::Request(int num, string name) {
		counter++;
		level = num;
		content = name;
		cout << counter << "." << content << endl;		//����Request�����ͬʱ��ӡ�����
}
int Request::getLevel() {
		return this->level;
}
int Request::counter = 0;		//��ʼ����������Ϊ0

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
		cout << "��������Leader����" << endl;
	}
	else {
		if (this->getNextHandler() != nullptr) {
			this->getNextHandler()->handleRequest(level);
		}
		else cout << "�������,�޷�����" << endl;
	}
}


void Manager::handleRequest(int level) {
	if (level >= 4 && level < 7) {
		cout << "��������Manager����" << endl;
	}
	else {
		if (this->getNextHandler() != nullptr) {
			this->getNextHandler()->handleRequest(level);
		}
		else cout << "�������,�޷�����" << endl;
	}
}


void Boss::handleRequest(int level) {
	if (level >= 7 && level < 10) {
		cout << "��������Boss����" << endl;
	}
	else {
		if (this->getNextHandler() != nullptr) {
			this->getNextHandler()->handleRequest(level);
		}
		else cout << "�������˴���" << endl;
	}
}
