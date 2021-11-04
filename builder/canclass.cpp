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
* 函数：can::returncost
* 参数：null
* 功能：返回罐头成本
*/
double can::returncost() {
	return cost;
}

/*
* 函数：can::returnnumber
* 参数：null
* 功能：返回罐头编号
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
	cout << "can_set_adapter:can_set_adapter:适配器模式，将can类型转换为canclass类型" << endl;
	tool = temp;
}

/*
* 函数：can_set_adapter::getbigprice
* 参数：null
* 功能：获取某种罐头大包装的成本
*/
double can_set_adapter::getbigprice() {
	return tool->getbigprice();
}

/*
* 函数：can_set_adapter::getsmallprice
* 参数：null
* 功能：获取某种罐头小包装的成本
*/
double can_set_adapter::getsmallprice() {
	return tool->getsmallprice();
}

/*
* 函数：can_set_adapter::protime
* 参数：null
* 功能：获取某种罐头的生产周期
*/
int can_set_adapter::protime() {
	return tool->getprotime();
}

can_set_adapter::~can_set_adapter() {
	delete tool;
}