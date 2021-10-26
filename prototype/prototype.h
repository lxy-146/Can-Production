#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include"header.h"

class Prototype
{
private:
    string str;
public:
    Prototype(string s)
    {
        str = s;
    }
    Prototype()
    {
        str = "";
    }
    void show()
    {
        cout << str << endl;
    }
    virtual Prototype* clone() = 0;
};

class ConcretePrototype :public Prototype
{
public:
    ConcretePrototype(string s) :Prototype(s)
    {}
    ConcretePrototype() {}
    virtual Prototype* clone()
    {
        ConcretePrototype* p = new ConcretePrototype();
        *p = *this;
        return p;
    }
};


class ConcretePrototype2 :public Prototype
{
public:
    ConcretePrototype2(string s) :Prototype(s)
    {}
    ConcretePrototype2() {}
    virtual Prototype* clone()
    {
        ConcretePrototype2* p = new ConcretePrototype2();
        *p = *this;
        return p;
    }
};

#endif

#pragma once
