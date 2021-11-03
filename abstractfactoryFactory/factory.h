#pragma once
/*
* ʵ��ģʽ�����󹤳�ģʽ������ģʽ
*/
#include"header.h"

class AbstractFactory;
class PackageFactory;
class KindFactory;
class Package;
class Kind;
class FruitIn;
class MeatIn;
class BigJar;
class LittleJar;

//���󹤳����������÷�
class FactoryProducer {
public:
	static AbstractFactory* getFactory(string);
};
//���������ĸ��࣬������
class AbstractFactory {
public:
	virtual Package* getPackage(string)=0;
	virtual Kind* getKind(string)=0;
};
//��װ�ӹ���
class PackageFactory :public AbstractFactory {
public:
	virtual Package* getPackage(string);
	virtual Kind* getKind(string);
};
//������ӹ���
class KindFactory :public AbstractFactory {
public:
	virtual Package* getPackage(string);
	virtual Kind* getKind(string);
};
//��װ�࣬�����࣬���װ��С��װ�ĸ���
class Package {
public:
	virtual void unmake() = 0;
	virtual void make() = 0;
};
//�����࣬������
class Kind {
public:
	virtual void unmake()=0;
	virtual void make() = 0;
};
//���װ��
class BigJar:public Package {
public:
	virtual void unmake();
	virtual void make();
};
//С��װ��
class LittleJar :public Package {
public:
	virtual void unmake();
	virtual void make();
};
//ˮ����
class FruitIn :public Kind {
public:
	virtual void unmake();
	virtual void make();
};
//����
class MeatIn :public Kind {
public:
	virtual void unmake();
	virtual void make();
};