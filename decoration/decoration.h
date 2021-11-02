#pragma once
//#ifndef DECORATION_H
//#define DECORATION_H

#include "header.h"
#include "can.h"
//���ļ�ʵ���˰�װģʽ���Թ�ͷ���а�װ�ӹ�
//��ͷ��װ�ӿڣ��̳��˹�ͷ��
class Can_pack :public Can {
protected:
	//��Ա������ͷ
	Can* can;
public:
    //���캯��������Ҫ���а�װ�Ĺ�ͷ
	Can_pack(Can* c) { this->can = c; }
	//չʾ��ͷ����
	void show();
};


//С��ͷ��װ�࣬ʵ���˹�ͷ��װ�ӿ�
class Small_Can :public Can_pack {
public:
	//���캯��������Ҫ���а�װ��С��ͷ�Ĺ�ͷ
	Small_Can(Can* can) :Can_pack(can) {}
	//չʾ��ͷ������
	void show();
private:
	//��װ��С��ͷ
	void pack(Can* can);
};


//���ͷ��װ�࣬ʵ���˹�ͷ��װ�ӿ�
class Big_Can :public Can_pack {
public:
	//���캯��������Ҫ���а�װ��С��ͷ�Ĺ�ͷ
	Big_Can(Can* can) :Can_pack(can) {}
	//չʾ��ͷ������
	void show();
private:
	//��װ�ɴ��ͷ
	void pack(Can* can);
};


//#endif
