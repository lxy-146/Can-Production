/*
* command.h-defination
*/
#include"header.h"
#include"command.h"
/*
* 函数：Broker::takeorder
* 参数：Order* order
* 功能：将order加入到命令列表中
*/
void Broker::takeorder(Order* order){
	cout << "command pattern add an order" << endl;
	orderlist.push_back(order);
}
/*
* 函数：Broker::placeorder
* 参数：null
* 功能：执行所有的order
*/
void Broker::placeorder() {
	for (auto i : orderlist)
	{
		i->execute();
	}
}
/*
* 函数：Broker::undo
* 参数：null
* 功能：撤销所有操作
*/
void Broker::undo() {
	for (list<Order*>::reverse_iterator i = orderlist.rbegin(); i != orderlist.rend(); i++)
	{
		(*i)->unexecute();
	}
}
/*
* 函数：Broker::clear
* 参数：null
* 功能：将所有在列表中的命令清除
*/
void Broker::clear() {
	orderlist.clear();
}
/*
* 函数：KMakeOrder::execute
* 参数：null
* 功能：执行种类的make函数，制造一个对应种类的内容物
*/
void KMakeOrder::execute() {
	kind->make();
}
/*
* 函数：PMakeOrder::execute
* 参数：null
* 功能：执行包装的make函数，制造一个对应包装的壳
*/
void PMakeOrder::execute() {
	package->make();
}
/*
* 函数：PMakeOrder::unexecute
* 参数：null
* 功能：执行包装的unmake函数，销毁对应元素
*/
void PMakeOrder::unexecute() {
	package->unmake();
}
/*
* 函数：KMakeOrder::unexecute
* 参数：null
* 功能：执行种类的unmake函数，销毁对应元素
*/
void KMakeOrder::unexecute() {
	kind->unmake();
}