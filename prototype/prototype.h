/*
* 实现模式：原型模式
*/
#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include"header.h"
#include"storehouse.h"

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
    /*
    * 函数：packConcPrototype
    * 功能：构造函数，通过传入的种类和大小，构造罐头的包装
    */
    packConcPrototype(string s, string t) {
        size = s;
        type = t;
    };
    /*
    * 函数：packConcPrototype::setType
    * 功能：传入类型，改变packConcPrototype对象的Type
    */
    void setType(string t)
    {
        cout << "packConcPrototype:setType:change Type" << endl;
        type = t;
    }
    /*
    * 函数：packConcPrototype::setSize
    * 功能：传入大小，改变packConcPrototype对象的size
    */
    void setSize(string s)
    {
        cout << "packConcPrototype:setSize:change size" << endl;
        size = s;
    }
    /*
    * 函数：packConcPrototype::display
    * 功能：对packConcPrototype对象的属性进行输出展示
    */
    void display()
    {
        //cout << "A " << size <<" "<< type <<" can is already packed!"<< endl;
        CanStore* canstore = CanStore::GetInstance();
        if (size == "small" && type == "fruit")
            canstore->AddCan(0, 1, 0, 0);
        else if (size == "big" && type == "fruit")
            canstore->AddCan(1, 0, 0, 0);
        else if (size == "big" && type == "meat")
            canstore->AddCan(0, 0, 1, 0);
        else if (size == "small" && type == "meat")
            canstore->AddCan(0, 0, 0, 1);
        //展示罐头种类以及大小
    }
    /*
    * 函数：packConcPrototype::clone
    * 功能：对已有的packConcPrototype对象进行拷贝
    */
    packAbsPrototype* clone() override
    {
        cout << "packConcPrototype:clone:clone current Prototype object" << endl;
        auto* p =new packConcPrototype(size, type);
        return p;
    }
   
};


#endif

#pragma once
