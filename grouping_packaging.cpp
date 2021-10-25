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

void can_group::showinfo() {
	cout << number << "���ײ�" << '\t' << name << endl;
	cout << "�۸�:" << price << endl;
	cout << "��ͷ����:" << size << endl;
	cout << "���߲˹�ͷ����:" << lv << '\t' << "С�߲˹�ͷ����:" << sv << endl;
	cout << "�����ͷ����:" << lm << '\t' << "С���ͷ����:" << sm << endl;
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
//**********************************group_builder���Ա��������*******************************
group_builder::group_builder(){
}

void group_builder::create_group() {
	cout << "�������ײ�����:";
	string _name;
	cin >> _name;
	can_group group(_name);
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
		}
	}
	int judge = group.confirm();
	if (judge == 1) { group_list.push_back(group); cout << "�ײ���ӳɹ�" << endl; }
	else cout << "�ײ����ʧ��" << endl;
}

void group_builder::show_all_group() {
	system("cls");
	cout << "��ǰ�ײ�:" << endl;
	vector<can_group>::iterator it = group_list.begin();
	while (it != group_list.end()) {
		it->showinfo();
		it++;
	}
}