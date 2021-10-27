#ifndef DECORATION_H
#define DECORATION_H

#include "header.h"
#include "can.h"

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
	cout << "(small)" << endl;
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
	cout << "(big)" << endl;
}

#endif
#pragma once