#pragma once
/*
* 实现模式：组合模式，建造模式，策略模式，状态模式
*/
#include"header.h"
#include"canclass.h"
class can_group {//罐头套餐类,此处使用了composite模式
protected:
	string name;//套餐名
	static int gnumber;//套餐数量
	int number;//套餐编号
	vector<can> content;//套餐内容
	double price;//套餐价格
	int size;//套餐罐头总数
	int lv;//大蔬菜数量
	int sv;//小蔬菜数量
	int lm;//大肉数量
	int sm;//小肉数量
public:
	static int test;
	void showinfo();
	void additem(can*item);
	can_group(string name);
	can_group();
};

//默认套餐建造类，应用了builder和stragety和state
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

//套餐建造类，此处应用了builder模式和composite模式
class group_builder {
private:
	vector<can_group> group_list;//套餐列表
public:
	group_builder();
	void create_group();
	void show_all_group();
};