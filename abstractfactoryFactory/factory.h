#pragma once
/*
* ʵ��ģʽ�����󹤳�ģʽ������ģʽ
*/
#include"header.h"

class AbstractFactory;
class PackedgeFactory;
class KindFactory;
class Packedge;
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
	virtual Packedge* getPackedge(string)=0;
	virtual Kind* getKind(string)=0;
};
//��װ�ӹ���
class PackedgeFactory :public AbstractFactory {
public:
	virtual Packedge* getPackedge(string);
	virtual Kind* getKind(string);
};
//������ӹ���
class KindFactory :public AbstractFactory {
public:
	virtual Packedge* getPackedge(string);
	virtual Kind* getKind(string);
};
//��װ�࣬�����࣬���װ��С��װ�ĸ���
class Packedge {
public:
	virtual void make() = 0;
};
//�����࣬������
class Kind {
public:
	virtual void make() = 0;
};
//���װ��
class BigJar:public Packedge {
public:
	virtual void make();
};
//С��װ��
class LittleJar :public Packedge {
public:
	virtual void make();
};
//ˮ����
class FruitIn :public Kind {
public:
	virtual void make();
};
//����
class MeatIn :public Kind {
public:
	virtual void make();
};