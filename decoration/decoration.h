#pragma once
//#ifndef DECORATION_H
//#define DECORATION_H

#include "header.h"
#include "can.h"
//此文件实现了包装模式，对罐头进行包装加工
//罐头包装接口，继承了罐头类
class Can_pack :public Can {
protected:
	//成员变量罐头
	Can* can;
public:
    //构造函数，传入要进行包装的罐头
	Can_pack(Can* c) { this->can = c; }
	//展示罐头种类
	void show();
};


//小罐头包装类，实现了罐头包装接口
class Small_Can :public Can_pack {
public:
	//构造函数，传入要进行包装成小罐头的罐头
	Small_Can(Can* can) :Can_pack(can) {}
	//展示罐头的种类
	void show();
private:
	//包装成小罐头
	void pack(Can* can);
};


//大罐头包装类，实现了罐头包装接口
class Big_Can :public Can_pack {
public:
	//构造函数，传入要进行包装成小罐头的罐头
	Big_Can(Can* can) :Can_pack(can) {}
	//展示罐头的种类
	void show();
private:
	//包装成大罐头
	void pack(Can* can);
};


//#endif
