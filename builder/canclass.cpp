#include"header.h"
#include"canclass.h"
#include"can.h"
can::can() {
	cost = 0; time = 0; number = 0;
}
double can::returncost() {
	return cost;
}
int can::returnnumber() {
	return number;
}

can_large_vegetable::can_large_vegetable() {
	Can* temp = new FruitCan();
	temp->setprice(4);
	cost = temp->getbigprice(); time = 6; number = 1;
	delete temp;
}

can_small_vegetable::can_small_vegetable() {
	Can* temp = new FruitCan();
	temp->setprice(4);
	cost = temp->getsmallprice(); time = 4; number = 2;
	delete temp;
}

can_large_meat::can_large_meat() {
	Can* temp = new MeatCan();
	temp->setprice(9);
	cost = temp->getbigprice(); time = 9; number = 3;
	delete temp;
}

can_small_meat::can_small_meat() {
	Can* temp = new MeatCan();
	temp->setprice(9);
	cost = temp->getsmallprice(); time = 6; number = 4;
	delete temp;
}