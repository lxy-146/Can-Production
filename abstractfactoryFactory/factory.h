#pragma once
/*
* 实现模式：抽象工厂模式、工厂模式
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

//抽象工厂的生产调用方
class FactoryProducer {
public:
	static AbstractFactory* getFactory(string);
};
//两个工厂的父类，抽象类
class AbstractFactory {
public:
	virtual Packedge* getPackedge(string)=0;
	virtual Kind* getKind(string)=0;
};
//包装加工厂
class PackedgeFactory :public AbstractFactory {
public:
	virtual Packedge* getPackedge(string);
	virtual Kind* getKind(string);
};
//内容物加工厂
class KindFactory :public AbstractFactory {
public:
	virtual Packedge* getPackedge(string);
	virtual Kind* getKind(string);
};
//包装类，抽象类，大包装和小包装的父类
class Packedge {
public:
	virtual void make() = 0;
};
//种类类，抽象类
class Kind {
public:
	virtual void make() = 0;
};
//大包装类
class BigJar:public Packedge {
public:
	virtual void make();
};
//小包装类
class LittleJar :public Packedge {
public:
	virtual void make();
};
//水果类
class FruitIn :public Kind {
public:
	virtual void make();
};
//肉类
class MeatIn :public Kind {
public:
	virtual void make();
};