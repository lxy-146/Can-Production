#pragma once
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

class FactoryProducer {
public:
	static AbstractFactory* getFactory(string);
};

class AbstractFactory {
public:
	virtual Packedge* getPackedge(string)=0;
	virtual Kind* getKind(string)=0;
};

class PackedgeFactory :public AbstractFactory {
public:
	virtual Packedge* getPackedge(string);
	virtual Kind* getKind(string);
};

class KindFactory :public AbstractFactory {
public:
	virtual Packedge* getPackedge(string);
	virtual Kind* getKind(string);
};

class Packedge {
public:
	virtual void make() = 0;
};

class Kind {
public:
	virtual void make() = 0;
};

class BigJar:public Packedge {
public:
	virtual void make();
};

class LittleJar :public Packedge {
public:
	virtual void make();
};

class FruitIn :public Kind {
public:
	virtual void make();
};

class MeatIn :public Kind {
public:
	virtual void make();
};