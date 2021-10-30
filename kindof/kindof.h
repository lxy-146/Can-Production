#ifndef KINDOF_H
#define KINDOF_H

#include "can.h"
#include<string>
#include<map>
#include<iostream>

using namespace std;

//惰性初始模式（惰性工厂）
//twin(双胞胎)模式

//肉罐头分类
class KindOfMeatCan :public MeatCan {
public:
	virtual void show();//显示罐头的种类
	static KindOfMeatCan* getMeatCan(const string& type);//显示肉罐头的种类
	static void printCurrentTypes();
	string gettype();//获得罐头的种类
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

	if (!f) {           //如果在map中找不到这种类型的肉罐头，就创建
		f = new KindOfMeatCan(type); //延迟初始化
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


//水果罐头分类
class KindOfFruitCan :public FruitCan {
public:
	virtual void show();//显示罐头的种类
	static KindOfFruitCan* getFruitCan(const string& type);//显示水果罐头种类
	static void printCurrentTypes();
	string gettype();//获得水果罐头种类
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

	if (!f) {           //如果在map中找不到这种类型的水果罐头，就创建
		f = new KindOfFruitCan(type); //延迟初始化
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

//蔬菜罐头分类
class KindOfVegCan :public VegCan {
public:
	virtual void show();//显示蔬菜罐头
	static KindOfVegCan* getVegCan(const string& type, KindOfMeatCan* m);//不同类型蔬菜罐头
	static void printCurrentTypes();
	string gettype();//得到蔬菜罐头种类
	void mixed();//混合类型关头
private:
	static map<string, KindOfVegCan*> types;
	string type;
	KindOfMeatCan* meat = NULL;
	KindOfVegCan(const string& t, KindOfMeatCan* m) :type(t), meat(m) {}//蔬菜可以和肉混合组成罐头
};

map<string, KindOfVegCan*> KindOfVegCan::types;

void KindOfVegCan::show() {
	cout << "This is a " << type << " can" << endl;
}

string KindOfVegCan::gettype() {
	return type;
}

void KindOfVegCan::mixed() {//检测是否有肉的成分，再进行输出
	if (meat == NULL)show();
	else {
		cout << "This is a " << type << " and " << meat->gettype() << " can" << endl;
	}
}

KindOfVegCan* KindOfVegCan::getVegCan(const string& type, KindOfMeatCan* m) {
	KindOfVegCan*& f = types[type];

	if (!f) {           //如果在map中找不到这种类型的水果罐头，就创建
		f = new KindOfVegCan(type, m); //延迟初始化
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
