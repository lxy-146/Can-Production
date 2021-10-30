#pragma once
class Can //��ͷ��
{
public:
	Can() { price = 0; produce_time = 0; }
	Can(int p,int pt):price(p), produce_time(pt) {}
	virtual void show() = 0;
	void setprice(int);
	int  getbigprice();
	int getsmallprice();
	int getprotime();
protected:
	int price;
	int produce_time;
};

//���ͷ
class MeatCan :public Can {
public:
	MeatCan(){ price = 0; produce_time = 0; }
	MeatCan(int p,int pt);
	virtual void show();
};

//ˮ����ͷ
class FruitCan :public Can {
public:
	FruitCan() { price = 0; produce_time = 0; }
	FruitCan(int p,int pt);
	virtual void show();
};

//�߲˹�ͷ
class VegCan :public Can {
public:
	virtual void show() = 0;
};