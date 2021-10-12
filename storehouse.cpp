#include"storehouse.h"
#include"header.h"

FruitStore* FruitStore::fruitstore = nullptr;

FruitStore::~FruitStore() {
	cout << "fruitstore is dead" << endl;
}

FruitStore* FruitStore::GetInstance() {
	if (fruitstore == nullptr) {
		fruitstore = new FruitStore();
		cout << "fruitstore is established" << endl;
	}
	return fruitstore;
}

int FruitStore::getnum() {
	return fruitnum;
}

void FruitStore::addnum(int n) {
	fruitnum=fruitnum+n;
	cout << "current fruit number is " << fruitnum << endl;
}


void FruitStore::decreasenum(int n) {
	assert(n <=fruitnum);
	fruitnum = fruitnum - n;
}




MeatStore* MeatStore::meatstore = nullptr;

MeatStore::~MeatStore() {
	cout << "meatstore is dead" << endl;
}

MeatStore* MeatStore::GetInstance() {
	if (meatstore == nullptr) {
		meatstore = new MeatStore();
		cout << "meatstore is established" << endl;
	}
	return meatstore;
}

int MeatStore::getnum() {
	return meatnum;
}

void MeatStore::addnum(int n) {
	meatnum = meatnum + n;
	cout << "current meat number is " << meatnum << endl;
}

void MeatStore::decreasenum(int n) {
	assert(n<=meatnum);
	meatnum = meatnum - n;
}