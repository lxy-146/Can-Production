#include"header.h"
#include"can.h"

void MeatCan::show() {
	cout << "this is a meat can!" << endl;
}

void Can::setprice(int p) {
	if (p >= 0)
		price = p;
}

int Can::getbigprice() {
	return 1.5 * price;
}

int Can::getsmallprice() {
	return price;
}

int Can::getprotime() {
	return produce_time;
}

void FruitCan::show() {
	cout << "this is a fruit can!" << endl;
}