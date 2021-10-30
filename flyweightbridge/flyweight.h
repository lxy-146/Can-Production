#ifndef _bridge_H_
#define _bridge_H_

#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Kind {
public:
    virtual void produceKind(){}
};

class FishKind : public Kind {
public:
    void produceKind()
    {
        cout <<"生产鱼中等罐头" << endl;
    }

};
class PorkKind : public Kind {
public:
    void produceKind(){
        cout << "生产猪肉中等罐头" << endl;
    }
};
class BeefKind : public Kind {
public:
    void produceKind(){
        cout << "生产牛肉中等罐头" << endl;
    }
};

class Can {
public:
    virtual void produce(int num) = 0;
};

class newCan {
public:
    virtual void produceSize(Kind *kind){}
};

class MiddleCan: public newCan {
public:
    void produceSize(Kind *kind){
        kind->produceKind();
    }
};

class ConcreteCan : public Can{
public:
    ConcreteCan(string variety) {
        this->variety = variety;
    }
    void produce(int num) {
        cout << "罐头" << num << ":" << variety << endl;
    }
private:
    string variety;
    int num;
};

class Factory {
public:
    Factory() {
        flyweights.insert(make_pair("水果大罐头", new ConcreteCan("水果大罐头")));
        flyweights.insert(make_pair("水果小罐头", new ConcreteCan("水果小罐头")));
        flyweights.insert(make_pair("肉大罐头", new ConcreteCan("肉大罐头")));
        flyweights.insert(make_pair("肉小罐头", new ConcreteCan("肉小罐头")));
    }
    Can* GetFlyweights(string key) {
        flyweights.insert(make_pair(key, new ConcreteCan(key)));
        return (Can*)flyweights[key];
    }

private:
    map<string, ConcreteCan*> flyweights;
};
#endif 
