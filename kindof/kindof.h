#ifndef KINDOF_H
#define KINDOF_H

#include "can.h"
#include<string>
#include<map>
#include<iostream>

using namespace std;

//���Գ�ʼģʽ�����Թ�����
//twin(˫��̥)ģʽ

//���ͷ����
class KindOfMeatCan :public MeatCan {
public:
	virtual void show();
	static KindOfMeatCan* getMeatCan(const string& type);
	static void printCurrentTypes();
	string gettype();
private:
	static map<string, KindOfMeatCan*> types;
	string type;

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
	virtual void show();
	static KindOfFruitCan* getFruitCan(const string& type);
	static void printCurrentTypes();
	string gettype();
private:
	static map<string, KindOfFruitCan*> types;
	string type;

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
	virtual void show();
	static KindOfVegCan* getVegCan(const string& type, KindOfMeatCan* m);
	static void printCurrentTypes();
	string gettype();
	void mixed();
private:
	static map<string, KindOfVegCan*> types;
	string type;
	KindOfMeatCan* meat = NULL;
	KindOfVegCan(const string& t, KindOfMeatCan* m) :type(t), meat(m) {}//�߲˿��Ժ�������ɹ�ͷ
};

map<string, KindOfVegCan*> KindOfVegCan::types;

void KindOfVegCan::show() {
	cout << "This is a " << type << " can" << endl;
}

string KindOfVegCan::gettype() {
	return type;
}

void KindOfVegCan::mixed() {//����Ƿ�����ĳɷ֣��ٽ������
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
