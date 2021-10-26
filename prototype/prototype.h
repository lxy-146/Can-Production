#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include"header.h"

class packAbsPrototype {
    //抽象原型类
public:
    //虚函数，待具体原型类实现
    virtual ~packAbsPrototype() = default;
    virtual packAbsPrototype* clone() = 0;
    //核心clone函数
    virtual void setType(string t) = 0;
    virtual void setSize(string s) = 0;
    virtual void display() = 0;
protected:
    packAbsPrototype() = default;
};

class packConcPrototype : public packAbsPrototype
{
private:
    string size, type;
public:
    
    packConcPrototype(string s, string t) {
        size = s;
        type = t;
    };

    void setType(string t)
    {
        type = t;
    }
    //设置罐头种类
    void setSize(string s)
    {
        size = s;
    }
    //设置罐头大小
    void display()
    {
        cout << "A " << size <<" "<< type <<" can is already packed!"<< endl;
        //展示罐头种类以及大小
    }
    packAbsPrototype* clone() override
    {
        auto* p =new packConcPrototype(size, type);
        return p;
    }
    //对已有对象进行拷贝
};


#endif

#pragma once
