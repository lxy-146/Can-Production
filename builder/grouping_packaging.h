#pragma once
/*
* ʵ��ģʽ�����ģʽ������ģʽ������ģʽ��״̬ģʽ
*/
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
	void showinfo();
	void additem(can*item);
	can_group(string name);
	can_group();
};

//Ĭ���ײͽ����࣬Ӧ����builder��stragety��state
class default_group {
public:
	default_group(string name) { mygroup = new can_group(name); type = 'A'; }
	void changetype(char t);
	can_group* getgroup();
	void makegroup();
private:
	can_group* mygroup;
	char type;
};

//�ײͽ����࣬�˴�Ӧ����builderģʽ��compositeģʽ
class group_builder {
private:
	vector<can_group> group_list;//�ײ��б�
public:
	group_builder();
	void create_group();
	void show_all_group();
};