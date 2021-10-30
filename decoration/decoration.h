#pragma once
//#ifndef DECORATION_H
//#define DECORATION_H

#include "header.h"
#include "can.h"

//��ͷ��װ�ӿ�
class Can_pack :public Can {
protected:
	Can* can;
public:
	Can_pack(Can* c) { this->can = c; }
	void show();
};


//С��ͷ
class Small_Can :public Can_pack {
public:
	Small_Can(Can* can) :Can_pack(can) {}
	void show();
private:
	void pack(Can* can);
};


//���ͷ
class Big_Can :public Can_pack {
public:
	Big_Can(Can* can) :Can_pack(can) {}
	void show();
private:
	void pack(Can* can);
};


//#endif
