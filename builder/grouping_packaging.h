#pragma once
//��װ����
#include"header.h"
#include"canclass.h"
class can_group {//��ͷ�ײ���,�˴�ʹ����compositeģʽ
protected:
	string name;//�ײ���
	static int gnumber;//�ײ�����
	int number;//�ײͱ��
	vector<can> content;//�ײ�����
	double price;//�ײͼ۸�
	int size;//�ײ͹�ͷ����
	int lv;//���߲�����
	int sv;//С�߲�����
	int lm;//��������
	int sm;//С������
public:
	static int test;
	void showinfo();//����̨��ʾ�ײ���Ϣ
	int confirm();//���ײ���Ϣ���浽����
	void additem(can*item);//Ϊ�ײ���ӹ�ͷ
	can_group(string name);
	can_group();
};


class default_group {//Ĭ���ײͽ����࣬Ӧ����builder��stragety
public:
	default_group(string name) { mygroup = new can_group(name); type = 'A'; }
	void changetype(char t);
	can_group* getgroup();
	void makegroup();
private:
	can_group* mygroup;
	char type;
};


class group_builder {//�ײͽ����࣬�˴�Ӧ����builderģʽ��compositeģʽ
private:
	vector<can_group> group_list;//�ײ��б�
public:
	group_builder();
	void create_group();//�����ײ�
	void show_all_group();//��ʾ�����ײ�
};