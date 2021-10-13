#ifndef DECORATION_H
#define DECORATION_H

#include "header.h"

//罐头类
class Can {
public:
	void virtual show();//声明为虚函数
};
void Can::show() {
	cout << "这是一个罐头....";
}

//蔬菜罐头
class Veg_Can :public Can {
public:
	void show();
};
void Veg_Can::show() {
	cout << "这是一个蔬菜罐头";
}

//肉罐头
class Meat_Can :public Can {
public:
	void show();
};
void Meat_Can::show() {
	cout << "这是一个肉类罐头";
}

//罐头分装接口
class Can_pack :public Can {
protected:
	Can* can;
public:
	Can_pack(Can* c) { this->can = c; }
	void show();
};
void Can_pack::show() {
	can->show();
}

//小罐头
class Small_Can :public Can_pack {
public:
	Small_Can(Can* can) :Can_pack(can) {}
	void show();
private:
	void pack(Can* can);
};
void Small_Can::show() {
	can->show();
	pack(can);
}
void Small_Can::pack(Can* can) {
	cout << "(小瓶)" << endl;
}

//大罐头
class Big_Can :public Can_pack {
public:
	Big_Can(Can* can) :Can_pack(can) {}
	void show();
private:
	void pack(Can* can);
};
void Big_Can::show() {
	can->show();
	pack(can);
}
void Big_Can::pack(Can* can) {
	cout << "(大瓶)" << endl;
}

#endif
#pragma once