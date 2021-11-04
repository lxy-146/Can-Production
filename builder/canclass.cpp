/*
* canclass.h-defination
*/
#include"header.h"
#include"canclass.h"
#include"can.h"
can::can() {
	cost = 0; time = 0; number = 0;
}

/*
* ������can::returncost
* ������null
* ���ܣ����ع�ͷ�ɱ�
*/
double can::returncost() {
	return cost;
}

/*
* ������can::returnnumber
* ������null
* ���ܣ����ع�ͷ���
*/
int can::returnnumber() {
	return number;
}

can_large_vegetable::can_large_vegetable() {
	can_set_adapter* temp = new can_set_adapter(new FruitCan(4, 6));

	cost = temp->getbigprice(); time = temp->protime(); number = 1;
	delete temp;
}

can_small_vegetable::can_small_vegetable() {
	can_set_adapter* temp = new can_set_adapter(new FruitCan(4, 4));
	cost = temp->getsmallprice(); time = temp->protime(); number = 2;
	delete temp;
}

can_large_meat::can_large_meat() {
	can_set_adapter* temp = new can_set_adapter(new MeatCan(9, 9));
	cost = temp->getbigprice(); time = temp->protime(); number = 3;
	delete temp;
}

can_small_meat::can_small_meat() {
	can_set_adapter* temp = new can_set_adapter(new MeatCan(9, 6));
	cost = temp->getsmallprice(); time = temp->protime(); number = 4;
	delete temp;
}

can_set_adapter::can_set_adapter() {}

can_set_adapter::can_set_adapter(Can *temp) {
	cout << "can_set_adapter:can_set_adapter:������ģʽ����can����ת��Ϊcanclass����" << endl;
	tool = temp;
}

/*
* ������can_set_adapter::getbigprice
* ������null
* ���ܣ���ȡĳ�ֹ�ͷ���װ�ĳɱ�
*/
double can_set_adapter::getbigprice() {
	return tool->getbigprice();
}

/*
* ������can_set_adapter::getsmallprice
* ������null
* ���ܣ���ȡĳ�ֹ�ͷС��װ�ĳɱ�
*/
double can_set_adapter::getsmallprice() {
	return tool->getsmallprice();
}

/*
* ������can_set_adapter::protime
* ������null
* ���ܣ���ȡĳ�ֹ�ͷ����������
*/
int can_set_adapter::protime() {
	return tool->getprotime();
}

can_set_adapter::~can_set_adapter() {
	delete tool;
}