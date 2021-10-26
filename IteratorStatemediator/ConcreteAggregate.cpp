//����Ķ�������
#include"IteratorMode .h"

bool ConcreteAggregate::addOrder(int currentDay,int id,int now_day) //����µĶ���(�ж��Ƿ�Ϊ�գ�)
{	
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

void ConcreteAggregate::InfoUpgrate(int nowDay) {
	for (int i = 0; i < this->getSize(); i++)
	{//������������
		this->list[i].SetCurrentay(nowDay);
		this->list[i].GetState();
	}
}
int ConcreteAggregate::getSize() {
	//��ȡ����������
	int k = 0;
	vector<Order2>::iterator i;
	for (i = this->list.begin(); i != this->list.end(); ++i) {  //�õ�������������
		k++;
	}
	return k;
}

void ConcreteAggregate::showHtoT() {
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

void ConcreteAggregate::showTtoH() {
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

int ConcreteAggregate::deleteOrder() {
	//ɾ��ָ���Ķ���
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

void ConcreteAggregate::createIterator(ConcreteIterator* i,int start) {
	i->IniIterator(start, 0,0);
}

Order2 ConcreteAggregate::GetOrder(int id) {//��ȡָ����id�Ķ���
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