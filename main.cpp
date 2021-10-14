#include"header.h"
#include"storehouse.h"
#include"canfactory.h"
#include"stapleobserve.h"
#include"prototype.h"
#include"decoration.h"

int main() {
	OrderSubject* ordersubject=new OrderSubject();//创建一个与observe有关的subject类用来对observe进行控制
	Observe* fruitobserve = new FruitObserve();//水果方面的observe，与subject进行连接
	Observe* meatobserve = new MeatObserve();//肉方面的observe，与subject进行连接
	ordersubject->Attach(fruitobserve);//将水果observe进行连接
	ordersubject->Attach(meatobserve);//将肉observe进行连接
	ordersubject->SetOrder(10, 100);//创建一个订单
	ordersubject->SetOrder(100, 10);

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