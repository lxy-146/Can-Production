#include"grouping_packaging.h"
//***********************************can_group类成员函数定义*****************************
can_group::can_group() {
	name = "";
	number = price = size = lv = sv = lm = sm = 0;
}
int can_group::gnumber = 0;
int can_group::test = 0;

can_group::can_group(string name) {
	this->name = name;
	gnumber++;
	number = gnumber;
	price = size = lv = sv = lm = sm = 0;
}

void can_group::showinfo() {
	cout << number << "号套餐" << '\t' << name << endl;
	cout << "价格:" << price << endl;
	cout << "罐头总数:" << size << endl;
	cout << "大蔬菜罐头数量:" << lv << '\t' << "小蔬菜罐头数量:" << sv << endl;
	cout << "大肉罐头数量:" << lm << '\t' << "小肉罐头数量:" << sm << endl;
}

void can_group::additem(can* item) {
	content.push_back(*item);
	price += ((item->returncost()) * 1.5);
	size++;
	switch (item->returnnumber()) {
	case 1: {
		lv++;
		break;
	}
	case 2: {
		sv++;
		break;
	}
	case 3: {
		lm++;
		break;
	}
	case 4: {
		sm++;
		break;
	}
	}
}
int can_group::confirm() {
	return 1;
}
//**********************************default_group类成员函数定义*******************************
void default_group::changetype(char t) {
	if (t == 'A' || t == 'B') type = t;
}

can_group* default_group::getgroup() {
	return mygroup;
}

void default_group::makegroup() {
	if (type == 'A') {
		mygroup->additem(new can_large_meat());
		mygroup->additem(new can_small_vegetable());
	}
	else if (type == 'B') {
		mygroup->additem(new can_small_meat());
		mygroup->additem(new can_large_vegetable());
	}
}
//**********************************group_builder类成员函数定义*******************************
group_builder::group_builder(){
}

void group_builder::create_group() {
	cout << "请输入套餐名称:";
	string _name;
	char _a;
	cin >> _name;
	cout << "请输入是否使用默认套餐（若使用请输入套餐序号（A/B），若不使用请输入除AB外任意字符）：";
	cin >> _a;
	can_group group(_name);
	default_group dgroup(_name);
	if (_a == 'A') {
		dgroup.changetype('A');
		dgroup.makegroup();
		group_list.push_back(*dgroup.getgroup()); 
		cout << "套餐添加成功" << endl;
		return;
	}
	else if (_a == 'B') {
		dgroup.changetype('B');
		dgroup.makegroup();
		group_list.push_back(*dgroup.getgroup());
		cout << "套餐添加成功" << endl;
		return;
	}
	cout << "请输入想要加入的罐头编号并回车\n1:大蔬菜罐头 2:小蔬菜罐头 3:大肉罐头 4:小肉罐头 0:确认" << endl;
	int op = -1;
	while (op != 0) {
		cin >> op;
		switch (op) {
		case 1: {
			group.additem(new can_large_vegetable());
			cout << "大蔬菜罐头添加成功" << endl;
			break;
		}
		case 2: {
			group.additem(new can_small_vegetable());
			cout << "小蔬菜罐头添加成功" << endl;
			break;
		}
		case 3: {
			group.additem(new can_large_meat());
			cout << "大肉罐头添加成功" << endl;
			break;
		}
		case 4: {
			group.additem(new can_small_meat());
			cout << "小肉罐头添加成功" << endl;
			break;
		}
		default:break;
		}
	}
	int judge = group.confirm();
	if (judge == 1) { group_list.push_back(group); cout << "套餐添加成功" << endl; }
	else cout << "套餐添加失败" << endl;
}

void group_builder::show_all_group() {
	system("cls");
	cout << "当前套餐:" << endl;
	vector<can_group>::iterator it = group_list.begin();
	while (it != group_list.end()) {
		it->showinfo();
		it++;
	}
}