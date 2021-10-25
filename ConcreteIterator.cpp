//具体的迭代器
#include"IteratorMode .h"

Order2 ConcreteIterator::first(ConcreteAggregate* list) {
	if (this->count != 0)
	{//获取第一个
		this->current = this->start;
		cout << "当前查看的订单的id为：" << this->current << endl;
		return list->GetOrder(this->current);
		//start一定是第一个订单,但是订单可能会被删除需要更新
	}
	else
		cout << "当前还不存在订单" << endl;
}

Order2 ConcreteIterator::next(ConcreteAggregate* list) {
	if (this->count == 0)
		cout << "当前不存在订单" << endl;
	else {
		//获取current的下一个,需要判断是否是最后一个
		if ((this->current) + 1 < (this->start) + (this->count))
		{
			(this->current)++;
		}
		else
			cout << "当前已经是最后一个订单" << endl;
		cout << "当前查看的订单的id为：" << this->current << endl;
		return list->GetOrder((this->current));
	}
}

Order2 ConcreteIterator::end(ConcreteAggregate* list) {
	if (this->count == 0)
	{
		cout << "当前不存在订单" << endl;
	}		
	else {
		//获取所有订单的最后一个
		this->current = this->start + this->count - 1;
		cout << "当前查看的订单的id为：" << this->current << endl;
		return list->GetOrder(this->current);
	}
}

Order2 ConcreteIterator::now(ConcreteAggregate* list) {
	if (this->count == 0)
		cout << "当前不存在订单" << endl;
	else {
		//获取当前订单
		cout << "当前查看的订单的id为：" << this->current << endl;
		return list->GetOrder(this->current);
	}
}

bool ConcreteIterator::isEmpty(ConcreteAggregate* list) {
	if (this->count == 0)
		return true;
	else
		return false;
}
