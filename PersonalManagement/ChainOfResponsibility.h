/*
*ʵ��ģʽ��������ģʽ
*/

#include"header.h"

//������
class Request {
public:
	Request(int num, string name);
	int getLevel();
	static int counter;				//���ڸ��������ͱ�ţ��ڴ�ӡ����ѡ��ʱ���õ���
private:
	int level;						//����ĵȼ�
	string content;					//��������
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