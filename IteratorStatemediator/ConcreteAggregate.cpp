/*
* IteratorMode.h - Definition
*/

//具体的订单容器
#include"IteratorMode .h"

/*
   函数：ConcreteAggregate::addOrder
   参数：int id,int now_day
   功能：添加对应id的订单以及通过当前时间确定状态
*/
bool ConcreteAggregate::addOrder(int id,int now_day) //添加新的订单(判断是否为空？)
{	
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "addOrder" << "action description:" << "添加新的订单"<<endl;
	//订单类的实体order
	Order2* order = new Order2(new CreationState(),now_day);
	//输入订单的要求来确定订单的实现所需时间
	order->SumDays();
	order->SetID(id);
	//根据时间调整、输出状态
	cout << "这一订单的状态随时间变化如下:" << endl;
	for (int i = 1; i <= order->GetDay(); i +=1)
	{
		order->SetCurrentay(i);
		order->GetState();
		order->ShowState();
	}
	order->SetCurrentay(now_day);//状态重置
	order->SetState(new CreationState());
	this->list.push_back(*order);
	return true;
}

/*
   函数：ConcreteAggregate::InfoUpgrate
   参数：int nowDay
   功能：通过当前日期，遍历订单更新订单信息
*/
void ConcreteAggregate::InfoUpgrate(int nowDay) {
	for (int i = 0; i < this->getSize(); i++)
	{//遍历订单更新
		this->list[i].SetCurrentay(nowDay);
		this->list[i].GetState();
	}
}
/*
   函数：ConcreteAggregate::getSize
   参数：null
   功能：获取订单的总数
*/
int ConcreteAggregate::getSize() {
	//获取订单的总数
	int k = 0;
	vector<Order2>::iterator i;
	for (i = this->list.begin(); i != this->list.end(); ++i) {  //用迭代器遍历容器
		k++;
	}
	return k;
}

/*
   函数：ConcreteAggregate::showHtoT
   参数：null
   功能：从头到尾遍历容器输出订单信息
*/
void ConcreteAggregate::showHtoT() {
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "showHtoT" << "action description:" << "从头到尾遍历容器输出订单信息" << endl;
	if (this->getSize() == 0)
		cout << "当前还没有订单" << endl;
	else {
		vector<Order2>::iterator i;
		for (i = this->list.begin(); i != this->list.end(); ++i) {  //用迭代器遍历容器
			cout << "订单id为" << i->GetID() << "的订单当前信息为:";
			i->ShowState();
		}
		cout << endl;
		cout << "当前的订单信息输出完成" << endl;
	}
}

/*
   函数：ConcreteAggregate::showTtoH
   参数：null
   功能：从尾到头遍历容器输出订单信息
*/
void ConcreteAggregate::showTtoH() {
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "showTtoH" << "action description:" << "从尾到头遍历容器输出订单信息" << endl;
	if (this->getSize() == 0)
		cout << "当前还没有订单" << endl;
	else {
		vector<Order2>::reverse_iterator i;
		for (i = this->list.rbegin(); i != this->list.rend(); ++i) {  //用迭代器遍历容器

			cout << "订单id为" << i->GetID() << "的订单当前信息为:";
			i->ShowState();
		}
		cout << endl;
		cout << "当前的订单信息输出完成" << endl;
	}
}

/*
   函数：ConcreteAggregate::deleteOrder
   参数：null
   功能：删除指定的订单
*/
int ConcreteAggregate::deleteOrder() {
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "deleteOrder" << "action description:" << "删除指定的订单" << endl;
	cout << "请输入您希望删除的订单的id" << endl;
	int id;
	cin >> id;
	//查找订单看是否存在
	if (this->getSize() == 0)
	{
		cout << "当前还没有订单" << endl;
		return false;
	}
	else {
		vector<Order2>::iterator i;
		for (i = this->list.begin(); i != this->list.end(); ++i) {  //用迭代器遍历容器
			if (i->GetID() == id)
			{
				this->list.erase(i);
				return true;
			 }
		}
	}
	cout << "未查找到目标订单" << endl;
	return false;
}

/*
   函数：ConcreteAggregate::createIterator
   参数：null
   功能：创建对应的迭代器
*/
void ConcreteAggregate::createIterator(ConcreteIterator* i,int start) {
	i->IniIterator(start, 0,0);
}

/*
   函数：ConcreteAggregate::GetOrder
   参数：int id
   功能：获取指定的id的订单
*/
Order2 ConcreteAggregate::GetOrder(int id) {
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "GetOrder" << "action description:" << "获取指定的id的订单" << endl;
	if (this->getSize() == 0)
	{
		cout << "当前还没有订单" << endl;
	}
	else {
		int C = 0;
		vector<Order2>::iterator i;
		for (i = this->list.begin(); i != this->list.end(); ++i,C++) {  //用迭代器遍历容器
			if (i->GetID() == id)
			{
				return list[C];
			}
		}
	}
	cout << "未查找到目标订单" << endl;
}