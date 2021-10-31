/*
* storehouse.h-defination
*/
#include"storehouse.h"
#include"header.h"

/*
* 函数：Storehouse::getnum
* 参数：null
* 功能：获取仓库中货物数量
*/
int Storehouse::getnum() {
	return num;
}
/*
* 函数：Storehouse::addnum
* 参数：int n
* 功能：增加货物数量
*/
void Storehouse::addnum(int n) {
	num = num + n;
}
/*
* 函数：Storehouse::decreasenum
* 参数：int n
* 功能：减少货物数量
*/
void Storehouse::decreasenum(int n) {
	num -= n;
}
//定义单例模式中静态变量
FruitStore* FruitStore::fruitstore = nullptr;
//析构函数：调试用
FruitStore::~FruitStore() {
}
/*
* 函数：FruitStore::GetInstance
* 参数：null
* 功能：判断此时是否有仓库的实例被创建，如果有则返回该实例，如果没有则创建一个
*/
FruitStore* FruitStore::GetInstance() {
	if (fruitstore == nullptr) {
		fruitstore = new FruitStore();
	}
	return fruitstore;
}
//定义单例模式中静态变量
MeatStore* MeatStore::meatstore = nullptr;
//析构函数：调试用
MeatStore::~MeatStore() {
}
/*
* 函数：MeatStore::GetInstance
* 参数：null
* 功能：判断此时是否有仓库的实例被创建，如果有则返回该实例，如果没有则创建一个
*/
MeatStore* MeatStore::GetInstance() {
	if (meatstore == nullptr) {
		meatstore = new MeatStore();
	}
	return meatstore;
}

CanStore* CanStore::canstore = nullptr;

CanStore* CanStore::GetInstance() {
	if (canstore == nullptr) {
		canstore = new CanStore();
	}
	return canstore;
}

int CanStore::GetLargeFruitCan() {
	return largefruitcan;
}

int CanStore::GetSmallFruitCan() {
	return smallfruitcan;
}

int CanStore::GetLargeMeatCan() {
	return largemeatcan;
}

int CanStore::GetSmallMeatCan() {
	return smallmeatcan;
}

void CanStore::AddCan(int largefruitcan, int smallfruitcan, int largemeatcan, int smallmeatcan) {
	this->largefruitcan += largefruitcan;
	this->smallfruitcan += smallfruitcan;
	this->largemeatcan += largemeatcan;
	this->smallmeatcan += smallmeatcan;
}

void CanStore::DecreaseCan(int largefruitcan, int smallfruitcan, int largemeatcan, int smallmeatcan) {
	this->largefruitcan -= largefruitcan;
	this->smallfruitcan -= smallfruitcan;
	this->largemeatcan -= largemeatcan;
	this->smallmeatcan -= smallmeatcan;
}

