/*
* ���ģʽ������ģʽ
*/
#ifndef STOREHOUSE_H
#define STOREHOUSE_H

//�ֿ��࣬���ڴ��ԭ��
class Storehouse {
public:
	Storehouse() { num = 0; }
	int getnum();
	void addnum(int);
	void decreasenum(int n);
protected:
	int num;
};
//���ˮ���Ĳֿ�
class FruitStore :public Storehouse {
public:
	FruitStore() {}
	~FruitStore();
	static FruitStore* GetInstance();
private:
	static FruitStore* fruitstore;
};
//�����Ĳֿ�
class MeatStore :public Storehouse {
public:
	MeatStore(){}
	~MeatStore();
	static MeatStore* GetInstance();

private:
	static MeatStore* meatstore;
};
#endif
#pragma once
