#include"storehouse.h"
#include"header.h"

FruitStore* FruitStore::fruitstore = nullptr;

FruitStore::~FruitStore() {
}

FruitStore* FruitStore::GetInstance() {
	if (fruitstore == nullptr) {
		fruitstore = new FruitStore();
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
}

MeatStore* MeatStore::GetInstance() {
	if (meatstore == nullptr) {
		meatstore = new MeatStore();
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