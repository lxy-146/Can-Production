#pragma once
#include"header.h"
#include"can.h"
class can {
protected:
	int number;//��ͷ���
	double cost;//��ͷ�ɱ�
	double time;//��ͷ��������
public:
	can();
	double returncost();
	int returnnumber();
};




class can_large_vegetable :public can {
public:
	can_large_vegetable();
};
class can_small_vegetable:public can {
public:
	can_small_vegetable();
};
class can_large_meat:public can {
public:
	can_large_meat();
};
class can_small_meat:public can {
public:
	can_small_meat();
};

class can_set_adapter {//������ģʽ��strategyģʽ
private:
	Can *tool;
public:
	can_set_adapter();
	can_set_adapter(Can *temp);
	~can_set_adapter();
	double getbigprice();
	double getsmallprice();
	int protime();
};