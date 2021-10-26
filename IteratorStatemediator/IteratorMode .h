#pragma once
//迭代器模式e
//这个迭代器模式目的是为了迭代所有的订单的状态然后输出
#include"header.h"
#include"OrderStateMode.h"

//抽象迭代器
class Iterator
{
public:
    Iterator() {};
    virtual ~Iterator() {};
    virtual void first() {};
    virtual void next() {};
};

//抽象聚合类
class Aggregate {
public:
    Aggregate() {};
    ~Aggregate() {};
};

class ConcreteAggregate;//具体聚合类声明

//具体迭代器
class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(){}
    virtual ~ConcreteIterator() {};
    void IniIterator(int a, int b,int c) { start = a; current = b; count = c; }//初始化赋值
    void show() { cout << start << " " << current << " " << count << endl; }
    void SetIterator(int a,int c){ start = a; count = c; }//赋值
    Order2 first(ConcreteAggregate* list);
    Order2 now(ConcreteAggregate* list);
    Order2 next(ConcreteAggregate* list);//需要判断是否是最后一个
    Order2 end(ConcreteAggregate* list);
    bool isEmpty(ConcreteAggregate* list);//需要判断是否为空？不为空才能够查看
private:
    int start;      //id开始的位置
    int current;  //当前位置
    int count;  //数量统计的辅助变量
};

//具体聚合类
class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate(vector<Order2>* v):list(*v) {};
    ~ConcreteAggregate() {};
    void showHtoT();//从头到尾遍历
    void showTtoH();//从尾到头遍历
    vector<Order2> GetIte() {
        return this->list;
    }
    void InfoUpgrate(int nowDay);//订单的信息更新
    bool addOrder(int currentDay, int id,int now_day);//添加新的订单
    int deleteOrder();//删除指定的订单
    Order2 GetOrder(int id);//获取指定的id的订单
    int getSize();//获取长度
    void createIterator(ConcreteIterator* i,int start);//创建具体迭代器
private:
    vector<Order2> list;
    //容器存储Order的list来遍历,每次产生一个订单都需要加入到list
};



