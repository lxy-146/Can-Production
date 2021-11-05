/*
* IteratorMode.h - Definition
*/

//����Ķ�������
#include"IteratorMode .h"

/*
   ������ConcreteAggregate::addOrder
   ������int id,int now_day
   ���ܣ���Ӷ�Ӧid�Ķ����Լ�ͨ����ǰʱ��ȷ��״̬
*/
bool ConcreteAggregate::addOrder(int id,int now_day) //����µĶ���(�ж��Ƿ�Ϊ�գ�)
{	
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "addOrder" << "action description:" << "����µĶ���"<<endl;
	//�������ʵ��order
	Order2* order = new Order2(new CreationState(),now_day);
	//���붩����Ҫ����ȷ��������ʵ������ʱ��
	order->SumDays();
	order->SetID(id);
	//����ʱ����������״̬
	cout << "��һ������״̬��ʱ��仯����:" << endl;
	for (int i = 1; i <= order->GetDay(); i +=1)
	{
		order->SetCurrentay(i);
		order->GetState();
		order->ShowState();
	}
	order->SetCurrentay(now_day);//״̬����
	order->SetState(new CreationState());
	this->list.push_back(*order);
	return true;
}

/*
   ������ConcreteAggregate::InfoUpgrate
   ������int nowDay
   ���ܣ�ͨ����ǰ���ڣ������������¶�����Ϣ
*/
void ConcreteAggregate::InfoUpgrate(int nowDay) {
	for (int i = 0; i < this->getSize(); i++)
	{//������������
		this->list[i].SetCurrentay(nowDay);
		this->list[i].GetState();
	}
}
/*
   ������ConcreteAggregate::getSize
   ������null
   ���ܣ���ȡ����������
*/
int ConcreteAggregate::getSize() {
	//��ȡ����������
	int k = 0;
	vector<Order2>::iterator i;
	for (i = this->list.begin(); i != this->list.end(); ++i) {  //�õ�������������
		k++;
	}
	return k;
}

/*
   ������ConcreteAggregate::showHtoT
   ������null
   ���ܣ���ͷ��β�����������������Ϣ
*/
void ConcreteAggregate::showHtoT() {
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "showHtoT" << "action description:" << "��ͷ��β�����������������Ϣ" << endl;
	if (this->getSize() == 0)
		cout << "��ǰ��û�ж���" << endl;
	else {
		vector<Order2>::iterator i;
		for (i = this->list.begin(); i != this->list.end(); ++i) {  //�õ�������������
			cout << "����idΪ" << i->GetID() << "�Ķ�����ǰ��ϢΪ:";
			i->ShowState();
		}
		cout << endl;
		cout << "��ǰ�Ķ�����Ϣ������" << endl;
	}
}

/*
   ������ConcreteAggregate::showTtoH
   ������null
   ���ܣ���β��ͷ�����������������Ϣ
*/
void ConcreteAggregate::showTtoH() {
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "showTtoH" << "action description:" << "��β��ͷ�����������������Ϣ" << endl;
	if (this->getSize() == 0)
		cout << "��ǰ��û�ж���" << endl;
	else {
		vector<Order2>::reverse_iterator i;
		for (i = this->list.rbegin(); i != this->list.rend(); ++i) {  //�õ�������������

			cout << "����idΪ" << i->GetID() << "�Ķ�����ǰ��ϢΪ:";
			i->ShowState();
		}
		cout << endl;
		cout << "��ǰ�Ķ�����Ϣ������" << endl;
	}
}

/*
   ������ConcreteAggregate::deleteOrder
   ������null
   ���ܣ�ɾ��ָ���Ķ���
*/
int ConcreteAggregate::deleteOrder() {
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "deleteOrder" << "action description:" << "ɾ��ָ���Ķ���" << endl;
	cout << "��������ϣ��ɾ���Ķ�����id" << endl;
	int id;
	cin >> id;
	//���Ҷ������Ƿ����
	if (this->getSize() == 0)
	{
		cout << "��ǰ��û�ж���" << endl;
		return false;
	}
	else {
		vector<Order2>::iterator i;
		for (i = this->list.begin(); i != this->list.end(); ++i) {  //�õ�������������
			if (i->GetID() == id)
			{
				this->list.erase(i);
				return true;
			 }
		}
	}
	cout << "δ���ҵ�Ŀ�궩��" << endl;
	return false;
}

/*
   ������ConcreteAggregate::createIterator
   ������null
   ���ܣ�������Ӧ�ĵ�����
*/
void ConcreteAggregate::createIterator(ConcreteIterator* i,int start) {
	i->IniIterator(start, 0,0);
}

/*
   ������ConcreteAggregate::GetOrder
   ������int id
   ���ܣ���ȡָ����id�Ķ���
*/
Order2 ConcreteAggregate::GetOrder(int id) {
	cout << "classname:" << "ConcreteAggregate" << "method name:" << "GetOrder" << "action description:" << "��ȡָ����id�Ķ���" << endl;
	if (this->getSize() == 0)
	{
		cout << "��ǰ��û�ж���" << endl;
	}
	else {
		int C = 0;
		vector<Order2>::iterator i;
		for (i = this->list.begin(); i != this->list.end(); ++i,C++) {  //�õ�������������
			if (i->GetID() == id)
			{
				return list[C];
			}
		}
	}
	cout << "δ���ҵ�Ŀ�궩��" << endl;
}