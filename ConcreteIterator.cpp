//����ĵ�����
#include"IteratorMode .h"

Order2 ConcreteIterator::first(ConcreteAggregate* list) {
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

Order2 ConcreteIterator::next(ConcreteAggregate* list) {
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

Order2 ConcreteIterator::end(ConcreteAggregate* list) {
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

Order2 ConcreteIterator::now(ConcreteAggregate* list) {
	if (this->count == 0)
		cout << "��ǰ�����ڶ���" << endl;
	else {
		//��ȡ��ǰ����
		cout << "��ǰ�鿴�Ķ�����idΪ��" << this->current << endl;
		return list->GetOrder(this->current);
	}
}

bool ConcreteIterator::isEmpty(ConcreteAggregate* list) {
	if (this->count == 0)
		return true;
	else
		return false;
}
