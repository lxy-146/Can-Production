#ifndef KINDOF_H
#define KINDOF_H

#include "can.h"
#include<string>
#include<map>
#include<iostream>

using namespace std;

//此文件实现了惰性工厂模式，实现了对罐头种类的进一步细分（肉罐头、蔬菜罐头、水果罐头的子罐头）
//使用了twin模式，对不同大类的罐头进行了组合，实现了蔬菜+肉罐头的混合种类
//惰性初始模式（惰性工厂）
//twin(双胞胎)模式

//肉罐头分类类
class KindOfMeatCan :public MeatCan {
public:
	//显示罐头的种类
	virtual void show();
	//从肉罐头工厂中获取某种类型的罐头
	static KindOfMeatCan* getMeatCan(const string& type);
	//展示肉罐头工厂中存在哪些种类的罐头
	static void printCurrentTypes();
	//获得罐头的种类
	string gettype();
private:
	//map，用于存储不同罐头实例
	static map<string, KindOfMeatCan*> types;
	//type，罐头的种类（细分）
	string type;
	//构造函数，传入肉罐头的种类
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

//展示罐头的种类数和种类
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
	//展示水果罐头工厂中存在哪些种类的罐头
	static void printCurrentTypes();
	//获得水果罐头种类
	string gettype();
private:
	//map，用于存储不同罐头实例
	static map<string, KindOfFruitCan*> types;
	//type，罐头的种类（细分）
	string type;
	//构造函数，传入水果罐头的种类
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
//展示罐头的种类数和种类
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
	//显示罐头的种类
	virtual void show();
	//从蔬菜罐头工厂中获取某种类型的罐头
	static KindOfVegCan* getVegCan(const string& type, KindOfMeatCan* m);
	//展示当前工厂内的罐头种类
	static void printCurrentTypes();
	//得到蔬菜罐头种类
	string gettype();
	//混合类型关头
	void mixed();
private:
	//map，用于存储不同罐头实例
	static map<string, KindOfVegCan*> types;
	//type，罐头的种类（细分）
	string type;
	//声明要参与组合的肉罐头，默认为null
	KindOfMeatCan* meat = NULL;
	//构造函数，参数为蔬菜罐头种类以及肉罐头实例的指针，蔬菜可以和肉混合组成罐头（twin模式的实现）
	KindOfVegCan(const string& t, KindOfMeatCan* m) :type(t), meat(m) {}
};

map<string, KindOfVegCan*> KindOfVegCan::types;

void KindOfVegCan::show() {
	cout << "This is a " << type << " can" << endl;
}

string KindOfVegCan::gettype() {
	return type;
}

//组合罐头展示函数，检测是否有肉的成分，再进行输出
void KindOfVegCan::mixed() {
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

//展示罐头的种类数和种类
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
