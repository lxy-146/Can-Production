#pragma once
/*
实现模式：享元模式、桥梁模式
*/
#include"header.h"
#include"factory.h"
#include"decoration.h"


//生产鱼类罐头
class FishKind :public Kind {
public:
	virtual void make();
};
//生产猪肉罐头
class PorkKind :public Kind {
	virtual void make();
};
//生产牛肉罐头
class BeefKind :public Kind {
	virtual void make();
};
//增加新的尺寸的中型罐头
class MiddleCan :public Package {
public:
	MiddleCan(Kind* k) :kind(k) {}
	virtual void make();
private:
	Kind* kind;
};
//通过哈希表匹配需要生产或管理的罐头类型
class Factory {
public:
	Factory(){}
	Can* GetFlyweights(string key);
private:
	map<string, Can_pack*> flyweights;
};



