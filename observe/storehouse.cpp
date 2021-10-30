/*
* storehouse.h-defination
*/
#include"storehouse.h"
#include"header.h"

/*
* ������Storehouse::getnum
* ������null
* ���ܣ���ȡ�ֿ��л�������
*/
int Storehouse::getnum() {
	return num;
}
/*
* ������Storehouse::addnum
* ������int n
* ���ܣ����ӻ�������
*/
void Storehouse::addnum(int n) {
	num = num + n;
}
/*
* ������Storehouse::decreasenum
* ������int n
* ���ܣ����ٻ�������
*/
void Storehouse::decreasenum(int n) {
	num -= n;
}
//���嵥��ģʽ�о�̬����
FruitStore* FruitStore::fruitstore = nullptr;
//����������������
FruitStore::~FruitStore() {
}
/*
* ������FruitStore::GetInstance
* ������null
* ���ܣ��жϴ�ʱ�Ƿ��вֿ��ʵ����������������򷵻ظ�ʵ�������û���򴴽�һ��
*/
FruitStore* FruitStore::GetInstance() {
	if (fruitstore == nullptr) {
		fruitstore = new FruitStore();
	}
	return fruitstore;
}
//���嵥��ģʽ�о�̬����
MeatStore* MeatStore::meatstore = nullptr;
//����������������
MeatStore::~MeatStore() {
}
/*
* ������MeatStore::GetInstance
* ������null
* ���ܣ��жϴ�ʱ�Ƿ��вֿ��ʵ����������������򷵻ظ�ʵ�������û���򴴽�һ��
*/
MeatStore* MeatStore::GetInstance() {
	if (meatstore == nullptr) {
		meatstore = new MeatStore();
	}
	return meatstore;
}