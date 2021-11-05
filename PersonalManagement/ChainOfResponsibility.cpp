/*
*ChainOfResponsibility.h-defination
*/

#include "ChainOfResponsibility.h"
using namespace std;

/*
*������Request::Request
*������int num, string name
*���ܣ�Request���캯��
*/
Request::Request(int num, string name) {
	counter++;
	level = num;
	content = name;
	cout << counter << "." << content << endl;		//����Request�����ͬʱ��ӡ�����
}
int Request::counter = 0;		//��ʼ����������Ϊ0
/*
*������Request::getLevel
*������null
*���ܣ�����Request�ĵȼ�
*/
int Request::getLevel() {
	return this->level;
}

/*
*������Handler::Handler
*������null
*���ܣ�Handler���캯��
*/
Handler::Handler() {
	nextHandler = nullptr;
}

/*
*������Handler::setNextHandler
*������Handler* nextHandler
*���ܣ����õ�ǰHandler����һ��Handler
*/
void Handler::setNextHandler(Handler* nextHandler) {
	this->nextHandler = nextHandler;
}

/*
*������Handler::getNextHandler
*������null
*���ܣ����ص�ǰHandler����һ��Handler
*/
Handler* Handler::getNextHandler() {
	return nextHandler;
}


void Handler::handleRequest(int) {};

/*
*������Leader::handleRequest
*������int level
*���ܣ�Leader����Ա������
*/
void Leader::handleRequest(int level) {
	cout << "Leader:handleRequest:Leader��������"<<endl;
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

/*
*������Manager::handleRequest
*������int level
*���ܣ�Manager����Ա������
*/
void Manager::handleRequest(int level) {
	cout<< "Manager:handleRequest:Manager��������" << endl;
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


/*
*������Boss::handleRequest
*������int level
*���ܣ�Boss����Ա������
*/
void Boss::handleRequest(int level) {
	cout << "Boss:handleRequest:Boss��������" << endl;
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
