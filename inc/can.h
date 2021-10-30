#pragma once
class Can //罐头类
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

//肉罐头
class MeatCan :public Can {
public:
	MeatCan(){ price = 0; produce_time = 0; }
	MeatCan(int p,int pt);
	virtual void show();
};

//水果罐头
class FruitCan :public Can {
public:
	FruitCan() { price = 0; produce_time = 0; }
	FruitCan(int p,int pt);
	virtual void show();
};

//蔬菜罐头
class VegCan :public Can {
public:
	virtual void show() = 0;
};