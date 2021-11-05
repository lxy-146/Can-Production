/*
* ���ģʽ������ģʽ
*/
#ifndef STOREHOUSE_H
#define STOREHOUSE_H

//�ֿ��࣬���ڴ��ԭ��
class Storehouse {
public:
	int getnum();
	void addnum(int);
	void decreasenum(int n);
protected:
	Storehouse() { num = 0; }
	int num;
};
//���ˮ���Ĳֿ�
class FruitStore :public Storehouse {
public:
	~FruitStore();
	static FruitStore* GetInstance();
private:
	FruitStore() {}
	static FruitStore* fruitstore;
};
//�����Ĳֿ�
class MeatStore :public Storehouse {
public:
	
	~MeatStore();
	static MeatStore* GetInstance();

private:
	MeatStore() {}
	static MeatStore* meatstore;
};
//��Ź�ͷ�Ĳֿ�
class CanStore  {
public:
	static CanStore* GetInstance();
	int GetLargeFruitCan();
	int GetSmallFruitCan();
	int GetLargeMeatCan();
	int GetSmallMeatCan();
	void AddCan(int, int, int, int);
	void DecreaseCan(int, int, int, int);
	void ShowAll();
private:
	CanStore() { largefruitcan = smallfruitcan = largemeatcan = smallmeatcan = 0; }
	int largefruitcan;
	int smallfruitcan;
	int largemeatcan;
	int smallmeatcan;
	static CanStore* canstore;
};
#endif
#pragma once
