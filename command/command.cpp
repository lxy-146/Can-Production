/*
* command.h-defination
*/
#include"header.h"
#include"command.h"
/*
* ������Broker::takeorder
* ������Order* order
* ���ܣ���order���뵽�����б���
*/
void Broker::takeorder(Order* order){
	cout << "command pattern add an order" << endl;
	orderlist.push_back(order);
}
/*
* ������Broker::placeorder
* ������null
* ���ܣ�ִ�����е�order
*/
void Broker::placeorder() {
	for (auto i : orderlist)
	{
		i->execute();
	}
}
/*
* ������Broker::undo
* ������null
* ���ܣ��������в���
*/
void Broker::undo() {
	for (list<Order*>::reverse_iterator i = orderlist.rbegin(); i != orderlist.rend(); i++)
	{
		(*i)->unexecute();
	}
}
/*
* ������Broker::clear
* ������null
* ���ܣ����������б��е��������
*/
void Broker::clear() {
	orderlist.clear();
}
/*
* ������KMakeOrder::execute
* ������null
* ���ܣ�ִ�������make����������һ����Ӧ�����������
*/
void KMakeOrder::execute() {
	kind->make();
}
/*
* ������PMakeOrder::execute
* ������null
* ���ܣ�ִ�а�װ��make����������һ����Ӧ��װ�Ŀ�
*/
void PMakeOrder::execute() {
	package->make();
}
/*
* ������PMakeOrder::unexecute
* ������null
* ���ܣ�ִ�а�װ��unmake���������ٶ�ӦԪ��
*/
void PMakeOrder::unexecute() {
	package->unmake();
}
/*
* ������KMakeOrder::unexecute
* ������null
* ���ܣ�ִ�������unmake���������ٶ�ӦԪ��
*/
void KMakeOrder::unexecute() {
	kind->unmake();
}