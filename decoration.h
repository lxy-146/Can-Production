#ifndef DECORATION_H
#define DECORATION_H

#include "header.h"

//��ͷ��
class Can {
public:
	void virtual show();//����Ϊ�麯��
};
void Can::show() {
	cout << "����һ����ͷ....";
}

//�߲˹�ͷ
class Veg_Can :public Can {
public:
	void show();
};
void Veg_Can::show() {
	cout << "����һ���߲˹�ͷ";
}

//���ͷ
class Meat_Can :public Can {
public:
	void show();
};
void Meat_Can::show() {
	cout << "����һ�������ͷ";
}

//��ͷ��װ�ӿ�
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

//С��ͷ
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
	cout << "(Сƿ)" << endl;
}

//���ͷ
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
	cout << "(��ƿ)" << endl;
}

#endif
#pragma once