#include"header.h"
#include"storehouse.h"
#include"canfactory.h"
#include"stapleobserve.h"

int main() {
	OrderSubject* ordersubject=new OrderSubject();
	Observe* fruitobserve = new FruitObserve();
	Observe* meatobserve = new MeatObserve();
	ordersubject->Attach(fruitobserve);
	ordersubject->Attach(meatobserve);
	ordersubject->SetOrder(10, 100);
	return 0;
}