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