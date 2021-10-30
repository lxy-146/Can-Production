#pragma once
#include"header.h"
#include"factory.h"
#include"decoration.h"



class FishKind :public Kind {
public:
	virtual void make();
};

class PorkKind :public Kind {
	virtual void make();
};

class BeefKind :public Kind {
	virtual void make();
};

class MiddleCan :public Package {
public:
	MiddleCan(Kind* k) :kind(k) {}
	virtual void make();
private:
	Kind* kind;
};

class Factory {
public:
	Factory(){}
	Can* GetFlyweights(string key);
private:
	map<string, Can_pack*> flyweights;
};



