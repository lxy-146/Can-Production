#include"header.h"
#include"storehouse.h"
#include"canfactory.h"
#include"stapleobserve.h"
#include"prototype.h"

int main() {
	OrderSubject* ordersubject=new OrderSubject();
	Observe* fruitobserve = new FruitObserve();
	Observe* meatobserve = new MeatObserve();
	ordersubject->Attach(fruitobserve);
	ordersubject->Attach(meatobserve);
	ordersubject->SetOrder(10, 100);

	//原型模式包装罐头
	ConcretePrototype* fruitCanPrototype = new ConcretePrototype("Fruit can is already packed.");
	fruitCanPrototype->show();
	ConcretePrototype2* fruitCan1 = (ConcretePrototype2*)fruitCanPrototype->clone();
	fruitCan1->show();
	ConcretePrototype2* fruitCan2 = (ConcretePrototype2*)fruitCanPrototype->clone();
	fruitCan2->show();

	return 0;
}