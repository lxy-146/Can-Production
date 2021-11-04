/*
* grouping_packaging.h-defination
*/
#include"grouping_packaging.h"

//***********************************can_group���Ա��������*****************************
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

/*
* ������can_group::showinfo
* ������null
* ���ܣ�����̨��ʾ�ײ���Ϣ
*/
void can_group::showinfo() {
	cout << number << "���ײ�" << '\t' << name << endl;
	cout << "�۸�:" << price << endl;
	cout << "��ͷ����:" << size << endl;
	cout << "���߲˹�ͷ����:" << lv << '\t' << "С�߲˹�ͷ����:" << sv << endl;
	cout << "�����ͷ����:" << lm << '\t' << "С���ͷ����:" << sm << endl;
}

/*
* ������can_group::additem
* ������can* item
* ���ܣ�Ϊ�ײ���ӹ�ͷ
*/
void can_group::additem(can* item) {
	cout << "can_group:additem:����ģʽ����ָ��ָ��Ķ������͵�����ͬ������������ͬ���" << endl;
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
//**********************************default_group���Ա��������*******************************
/*
* ������default_group::changetype
* ������char t
* ���ܣ��ı��ײͲ�������
*/
void default_group::changetype(char t) {
	if (t == 'A' || t == 'B') type = t;
}

/*
* ������default_group::getgroup()
* ������null
* ���ܣ���ȡ�ײ�
*/
can_group* default_group::getgroup() {
	return mygroup;
}

/*
* ������default_group::makegroup
* ������null
* ���ܣ����ݲ������ʹ����ײ�
*/
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
//**********************************group_builder���Ա��������*******************************
group_builder::group_builder(){
}

/*
* ������group_builder::create_group()
* ������null
* ���ܣ������ײ�
*/
void group_builder::create_group() {
	cout << "�������ײ�����:";
	string _name;
	char _a;
	cin >> _name;
	cout << "�������Ƿ�ʹ��Ĭ���ײͣ���ʹ���������ײ���ţ�A/B��������ʹ���������AB�������ַ�����";
	cin >> _a;
	can_group group(_name);
	cout << "group_builder:create_group:������ģʽ���ý����ߴ����µ��ײ���ʵ��" << endl;
	default_group dgroup(_name);
	if (_a == 'A') {
		dgroup.changetype('A');
		dgroup.makegroup();
		group_list.push_back(*dgroup.getgroup()); 
		cout << "�ײ���ӳɹ�" << endl;
		return;
	}
	else if (_a == 'B') {
		dgroup.changetype('B');
		dgroup.makegroup();
		group_list.push_back(*dgroup.getgroup());
		cout << "�ײ���ӳɹ�" << endl;
		return;
	}
	cout << "��������Ҫ����Ĺ�ͷ��Ų��س�\n1:���߲˹�ͷ 2:С�߲˹�ͷ 3:�����ͷ 4:С���ͷ 0:ȷ��" << endl;
	int op = -1;
	while (op != 0) {
		cin >> op;
		switch (op) {
		case 1: {
			group.additem(new can_large_vegetable());
			cout << "���߲˹�ͷ��ӳɹ�" << endl;
			break;
		}
		case 2: {
			group.additem(new can_small_vegetable());
			cout << "С�߲˹�ͷ��ӳɹ�" << endl;
			break;
		}
		case 3: {
			group.additem(new can_large_meat());
			cout << "�����ͷ��ӳɹ�" << endl;
			break;
		}
		case 4: {
			group.additem(new can_small_meat());
			cout << "С���ͷ��ӳɹ�" << endl;
			break;
		}
		default:cout << "��������ȷ��ֵ��"; break;
		}
	}
	group_list.push_back(group); 
	cout << "�ײ���ӳɹ�" << endl;
}

/*
* ������group_builder::show_all_group
* ������null
* ���ܣ���ʾ�����ײ�
*/
void group_builder::show_all_group() {
	system("cls");
	cout << "��ǰ�ײ�:" << endl;
	vector<can_group>::iterator it = group_list.begin();
	while (it != group_list.end()) {
		it->showinfo();
		it++;
	}
}