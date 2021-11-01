/*
* ʵ��ģʽ���ն���ģʽ������ģʽ
*/
#ifndef NULLOBJECT_H
#define NULLOBJECT_H
#include<iostream>
#include<string>
using namespace std;

//����һ��������AbstractBuyer��ʾ�ɹ��̡�
class AbstractBuyer
{
public:
	//�麯����������ɹ��̶���̳�ʵ��
	AbstractBuyer() {};
	virtual ~AbstractBuyer() {};
	/*
	* ������isNull
	* ���ܣ�ȷ���ɹ����Ƿ������ǵ��嵥��
	*/
	virtual bool isNull() = 0;
	/*
	* ������getName
	* ���ܣ����زɹ��̵����ƣ��������嵥�ϣ�������ʾ��Ϣ
	*/
	virtual string getName() = 0;
	//���캯���������������ж��Ƿ�Ϊ�յĲɹ���

protected:
	string name;
};

//������չ�˳�����AbstractBuyer��ʵ����RealBuyer��
class RealBuyer :AbstractBuyer
{
public:
	RealBuyer(string tname) { name = tname; };
	~RealBuyer() {};
	bool isNull() { return false; };
	string getName() { return name; };
};

//������չ�˳�����AbstractBuyer�Ŀ���NullBuyer��
class NullBuyer :AbstractBuyer
{
public:
	NullBuyer() {};
	~NullBuyer() {};
	bool isNull() { return true; };
	string getName() { return "It is NOT on our buyer list!"; };
};

//����BuyerFactory�࣬������ȡʵ���������ʵ��
class BuyerFactory
{
public:
	BuyerFactory() {};
	~BuyerFactory() {};
	static string name[4];
	static AbstractBuyer* getBuyer(string tname);
	//�ɹ����嵥�Ĺ���
};

string BuyerFactory::name[4] = { "WalMart","Carrefour","Hualian","Darunfa" };

/*
* ������BuyerFactory::getBuyer
* ���ܣ�����ģʽ�������ɸ��ɹ��̣��������嵥�Ϲ���ΪNullBuyer������ΪRealBuyer
*/
AbstractBuyer* BuyerFactory::getBuyer(string tname)
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (name[i] == tname)
		{
			//��tname�ڲɹ����嵥���򷵻�RealBuyer
			return (AbstractBuyer*)new RealBuyer(tname);
		}
	}
	return (AbstractBuyer*)new NullBuyer();
	//ʹ�ù���ģʽ���ɲɹ����嵥�õ�һ�вɹ���
}

#endif

#pragma once