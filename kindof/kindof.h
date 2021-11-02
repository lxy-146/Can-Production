#ifndef KINDOF_H
#define KINDOF_H

#include "can.h"
#include<string>
#include<map>
#include<iostream>

using namespace std;

//���ļ�ʵ���˶��Թ���ģʽ��ʵ���˶Թ�ͷ����Ľ�һ��ϸ�֣����ͷ���߲˹�ͷ��ˮ����ͷ���ӹ�ͷ��
//ʹ����twinģʽ���Բ�ͬ����Ĺ�ͷ��������ϣ�ʵ�����߲�+���ͷ�Ļ������
//���Գ�ʼģʽ�����Թ�����
//twin(˫��̥)ģʽ

//���ͷ������
class KindOfMeatCan :public MeatCan {
public:
	//��ʾ��ͷ������
	virtual void show();
	//�����ͷ�����л�ȡĳ�����͵Ĺ�ͷ
	static KindOfMeatCan* getMeatCan(const string& type);
	//չʾ���ͷ�����д�����Щ����Ĺ�ͷ
	static void printCurrentTypes();
	//��ù�ͷ������
	string gettype();
private:
	//map�����ڴ洢��ͬ��ͷʵ��
	static map<string, KindOfMeatCan*> types;
	//type����ͷ�����ࣨϸ�֣�
	string type;
	//���캯�����������ͷ������
	KindOfMeatCan(const string& t) :type(t) {}
};

map<string, KindOfMeatCan*> KindOfMeatCan::types;

void KindOfMeatCan::show() {
	cout << "This is a " << type << " can" << endl;
}

string KindOfMeatCan::gettype() {
	return type;
}

KindOfMeatCan* KindOfMeatCan::getMeatCan(const string& type) {
	KindOfMeatCan*& f = types[type];

	if (!f) {           //�����map���Ҳ����������͵����ͷ���ʹ���
		f = new KindOfMeatCan(type); //�ӳٳ�ʼ��
	}
	return f;
}

//չʾ��ͷ��������������
void KindOfMeatCan::printCurrentTypes() {
	if (!types.empty()) {
		cout << "The number of kinds of meat can = " << types.size() << endl;
		for (map<string, KindOfMeatCan*>::iterator iter = types.begin(); iter != types.end(); ++iter) {
			cout << (*iter).first << endl;
		}
		cout << endl;
	}
}


//ˮ����ͷ����
class KindOfFruitCan :public FruitCan {
public:
	virtual void show();//��ʾ��ͷ������
	static KindOfFruitCan* getFruitCan(const string& type);//��ʾˮ����ͷ����
	//չʾˮ����ͷ�����д�����Щ����Ĺ�ͷ
	static void printCurrentTypes();
	//���ˮ����ͷ����
	string gettype();
private:
	//map�����ڴ洢��ͬ��ͷʵ��
	static map<string, KindOfFruitCan*> types;
	//type����ͷ�����ࣨϸ�֣�
	string type;
	//���캯��������ˮ����ͷ������
	KindOfFruitCan(const string& t) :type(t) {}
};

map<string, KindOfFruitCan*> KindOfFruitCan::types;

void KindOfFruitCan::show() {
	cout << "This is a " << type << " can" << endl;
}

string KindOfFruitCan::gettype() {
	return type;
}

KindOfFruitCan* KindOfFruitCan::getFruitCan(const string& type) {
	KindOfFruitCan*& f = types[type];

	if (!f) {           //�����map���Ҳ����������͵�ˮ����ͷ���ʹ���
		f = new KindOfFruitCan(type); //�ӳٳ�ʼ��
	}
	return f;
}
//չʾ��ͷ��������������
void KindOfFruitCan::printCurrentTypes() {
	if (!types.empty()) {
		cout << "The number of kinds of fruit can = " << types.size() << endl;
		for (map<string, KindOfFruitCan*>::iterator iter = types.begin(); iter != types.end(); ++iter) {
			cout << (*iter).first << endl;
		}
		cout << endl;
	}
}

//�߲˹�ͷ����
class KindOfVegCan :public VegCan {
public:
	//��ʾ��ͷ������
	virtual void show();
	//���߲˹�ͷ�����л�ȡĳ�����͵Ĺ�ͷ
	static KindOfVegCan* getVegCan(const string& type, KindOfMeatCan* m);
	//չʾ��ǰ�����ڵĹ�ͷ����
	static void printCurrentTypes();
	//�õ��߲˹�ͷ����
	string gettype();
	//������͹�ͷ
	void mixed();
private:
	//map�����ڴ洢��ͬ��ͷʵ��
	static map<string, KindOfVegCan*> types;
	//type����ͷ�����ࣨϸ�֣�
	string type;
	//����Ҫ������ϵ����ͷ��Ĭ��Ϊnull
	KindOfMeatCan* meat = NULL;
	//���캯��������Ϊ�߲˹�ͷ�����Լ����ͷʵ����ָ�룬�߲˿��Ժ�������ɹ�ͷ��twinģʽ��ʵ�֣�
	KindOfVegCan(const string& t, KindOfMeatCan* m) :type(t), meat(m) {}
};

map<string, KindOfVegCan*> KindOfVegCan::types;

void KindOfVegCan::show() {
	cout << "This is a " << type << " can" << endl;
}

string KindOfVegCan::gettype() {
	return type;
}

//��Ϲ�ͷչʾ����������Ƿ�����ĳɷ֣��ٽ������
void KindOfVegCan::mixed() {
	if (meat == NULL)show();
	else {
		cout << "This is a " << type << " and " << meat->gettype() << " can" << endl;
	}
}

KindOfVegCan* KindOfVegCan::getVegCan(const string& type, KindOfMeatCan* m) {
	KindOfVegCan*& f = types[type];

	if (!f) {           //�����map���Ҳ����������͵�ˮ����ͷ���ʹ���
		f = new KindOfVegCan(type, m); //�ӳٳ�ʼ��
	}
	return f;
}

//չʾ��ͷ��������������
void KindOfVegCan::printCurrentTypes() {
	if (!types.empty()) {
		cout << "The number of kinds of vegetabel can = " << types.size() << endl;
		for (map<string, KindOfVegCan*>::iterator iter = types.begin(); iter != types.end(); ++iter) {
			cout << (*iter).first << endl;
		}
		cout << endl;
	}
}
#endif // !KINDOF_H

#pragma once
