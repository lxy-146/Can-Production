/*
*Finance.h-defination
*/

#include"Finance.h"

/*
*函数：Memento::Memento
*参数：string state, double fund
*功能：Memento构造函数
*/
Memento::Memento(string state, double fund) {
	this->state = state;
	this->fund = fund;
}

/*
*函数：Memento::setState
*参数：string state
*功能：设置备忘录状态信息
*/
void Memento::setState(string state) {
	this->state = state;
}

/*
*函数：Memento::getState
*参数：null
*功能：返回备忘录状态信息
*/
string Memento::getState() {
	return state;
}

/*
*函数：Originator::Originator
*参数：double fund
*功能：Originator构造函数，设定企业资金总数
*/
Originator::Originator(double fund) {
	this->fund = fund;
}

/*
*函数：Originator::setState
*参数：string state
*功能：设置当前账本状态
*/
void Originator::setState(string state) {
	cout << "Originator:setState:更新账本状态信息" << endl;
	this->state = state;
}

/*
*函数：Originator::getState
*参数：null
*功能：返回当前账本状态
*/
string Originator::getState() {
	return state;
}

/*
*函数：Originator::printInfo
*参数：null
*功能：打印当前账本信息
*/
void Originator::printInfo() {
	cout << "Originator:printInfo:显示账本状态信息" << endl;
	cout << "账本当前状态: " << this->getState() << "  ";
	cout << "资金总额: " << this->getFund() << endl;
}

/*
*函数：Originator::createMemento
*参数：null
*功能：将账本当前状态信息创建为一条备忘
*/
Memento* Originator::createMemento() {
	cout << "Originator:createMemento:创建一条记录保存当前状态信息"<<endl;
	return new Memento(state, fund);
}

/*
*函数：Originator::restoreMemento
*参数：Memento* m
*功能：恢复上一次记录的账本状态信息
*/
void Originator::restoreMemento(Memento* m) {
	cout << "Originator:restoreMemento:账本恢复至上一状态" << endl;
	this->setState(m->getState());
	this->printInfo();
}

/*
*函数：Originator::getFund
*参数：null
*功能：返回账本当前的资金总数
*/
double Originator::getFund() {
	return this->fund;
}

/*
*函数：Originator::setFund
*参数：int operation, double num
*功能：修改账本的资金总数
*/
void Originator::setFund(int operation, double num) {
	if (operation == 0) {
		cout << "资金数额变动..." << endl;
		this->fund -= num;
	}
	else if (operation == 1) {
		cout << "资金数额变动..." << endl;
		this->fund += num;
	}
	else cout << "operation error" << endl;
}

/*
*函数：Caretaker::addMemento
*参数：Memento* m
*功能：向备忘录中增加一条记录
*/
void Caretaker::addMemento(Memento* m) {
	cout << "Caretaker:addMemento:添加记录到备忘录中"<<endl;
	mementos.push_back(m);
}

/*
*函数：Caretaker::addMemento
*参数：null
*功能：返回备忘录中的最新的一条记录
*/
Memento* Caretaker::getMemento() {
	Memento* m = mementos.back();
	mementos.pop_back();			  //删除容器最后一个元素
	return m;						  //最后一个元素的引用
}

/*
*函数：Accountant::Accountant
*参数：Originator* org
*功能：Accountant构造函数，设置代理类的代理对象
*/
Accountant::Accountant(Originator* org) {
	this->originator = org;
}

/*
*函数：Accountant::printInfo
*参数：null
*功能：代理查询账本当前状态信息
*/
void Accountant::printInfo() {
	cout << "Accountant:printInfo:调用代理对象的printInfo函数" << endl;
	preRequest();
	originator->printInfo();
	postRequest();
}

/*
*函数：Accountant::preRequest
*参数：null
*功能：代理查询预处理
*/
void Accountant::preRequest() {
	cout << "会计正在查询..." << endl;
}

/*
*函数：Accountant::postRequest
*参数：null
*功能：代理查询后续处理
*/
void Accountant::postRequest() {
	cout << "会计查询结束" << endl;

}