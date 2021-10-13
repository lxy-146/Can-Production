#include"header.h"
#include"storehouse.h"
#include"canfactory.h"
#include"stapleobserve.h"
#include"prototype.h"
#include"decoration.h"

int main() {
	OrderSubject* ordersubject=new OrderSubject();
	Observe* fruitobserve = new FruitObserve();
	Observe* meatobserve = new MeatObserve();
	ordersubject->Attach(fruitobserve);
	ordersubject->Attach(meatobserve);
	ordersubject->SetOrder(10, 100);

	Can* veg_can = new Veg_Can();//实例化一个蔬菜罐头
	Can* meat_can = new Meat_Can();//实例化一个肉罐头

	Small_Can small_veg_can = Small_Can(veg_can);//生产小型蔬菜罐头
	Big_Can big_veg_can = Big_Can(veg_can);//生产大型蔬菜罐头
	small_veg_can.show();
	big_veg_can.show();

	Small_Can small_meat_can = Small_Can(meat_can);//生产小型蔬菜罐头
	Big_Can big_meat_can = Big_Can(meat_can);//生产大型蔬菜罐头
	small_meat_can.show();
	big_meat_can.show();

	//原型模式包装罐头
	ConcretePrototype* fruitCanPrototype = new ConcretePrototype("Fruit can is already packed.");
	fruitCanPrototype->show();
	ConcretePrototype2* fruitCan1 = (ConcretePrototype2*)fruitCanPrototype->clone();
	fruitCan1->show();
	ConcretePrototype2* fruitCan2 = (ConcretePrototype2*)fruitCanPrototype->clone();
	fruitCan2->show();

	return 0;
}