/*
* IteratorMode.h - Definition
*/
//����ĵ�����
#include"IteratorMode .h"

/*
   ������ConcreteIterator::first
   ������ConcreteAggregate* list
   ���ܣ���ȡ������һ��Ԫ��
*/
Order2 ConcreteIterator::first(ConcreteAggregate* list) {
	cout << "classname:" << "ConcreteIterator" << "method name:" << "first" << "action description:" << "��ȡ�����ۺ����һ��Ԫ��" << endl;
	if (this->count != 0)
	{//��ȡ��һ��
		this->current = this->start;
		cout << "��ǰ�鿴�Ķ�����idΪ��" << this->current << endl;
		return list->GetOrder(this->current);
		//startһ���ǵ�һ������,���Ƕ������ܻᱻɾ����Ҫ����
	}
	else
		cout << "��ǰ�������ڶ���" << endl;
}

/*
   ������ConcreteIterator::next
   ������ConcreteAggregate* list
   ���ܣ���ȡ��ǰָ��ָ�����һ��Ԫ��
*/
Order2 ConcreteIterator::next(ConcreteAggregate* list) {
	cout << "classname:" << "ConcreteIterator" << "method name:" << "next" << "action description:" << "��ȡ��ǰָ��ָ�����һ��Ԫ��" << endl;
	if (this->count == 0)
		cout << "��ǰ�����ڶ���" << endl;
	else {
		//��ȡcurrent����һ��,��Ҫ�ж��Ƿ������һ��
		if ((this->current) + 1 < (this->start) + (this->count))
		{
			(this->current)++;
		}
		else
			cout << "��ǰ�Ѿ������һ������" << endl;
		cout << "��ǰ�鿴�Ķ�����idΪ��" << this->current << endl;
		return list->GetOrder((this->current));
	}
}

/*
   ������ConcreteIterator::end
   ������ConcreteAggregate* list
   ���ܣ���ȡ�������һ��Ԫ��
*/
Order2 ConcreteIterator::end(ConcreteAggregate* list) {
	cout << "classname:" << "ConcreteIterator" << "method name:" << "end" << "action description:" << "��ȡ�������һ��Ԫ��" << endl;
	if (this->count == 0)
	{
		cout << "��ǰ�����ڶ���" << endl;
	}		
	else {
		//��ȡ���ж��������һ��
		this->current = this->start + this->count - 1;
		cout << "��ǰ�鿴�Ķ�����idΪ��" << this->current << endl;
		return list->GetOrder(this->current);
	}
}

/*
   ������ConcreteIterator::now
   ������ConcreteAggregate* list
   ���ܣ���ȡ��ǰָ��ָ���Ԫ��
*/
Order2 ConcreteIterator::now(ConcreteAggregate* list) {
	cout << "classname:" << "ConcreteIterator" << "method name:" << "now" << "action description:" << "��ȡ��ǰָ��ָ���Ԫ��" << endl;
	if (this->count == 0)
		cout << "��ǰ�����ڶ���" << endl;
	else {
		//��ȡ��ǰ����
		cout << "��ǰ�鿴�Ķ�����idΪ��" << this->current << endl;
		return list->GetOrder(this->current);
	}
}

/*
   ������ConcreteIterator::isEmpty
   ������ConcreteAggregate* list
   ���ܣ��ж������Ƿ�Ϊ��
*/
bool ConcreteIterator::isEmpty(ConcreteAggregate* list) {
	if (this->count == 0)
		return true;
	else
		return false;
}
