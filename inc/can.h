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
	virtual void show();
};

//ˮ����ͷ
class FruitCan :public Can {
public:
	virtual void show();
};

//�߲˹�ͷ
class VegCan :public Can {
public:
	virtual void show() = 0;
};