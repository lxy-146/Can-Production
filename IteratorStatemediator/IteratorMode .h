#pragma once
//������ģʽe
//���������ģʽĿ����Ϊ�˵������еĶ�����״̬Ȼ�����
#include"header.h"
#include"OrderStateMode.h"

//���������
class Iterator
{
public:
    Iterator() {};
    virtual ~Iterator() {};
    virtual void first() {};
    virtual void next() {};
};

//����ۺ���
class Aggregate {
public:
    Aggregate() {};
    ~Aggregate() {};
};

class ConcreteAggregate;//����ۺ�������

//���������
class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(){}
    virtual ~ConcreteIterator() {};
    void IniIterator(int a, int b,int c) { start = a; current = b; count = c; }//��ʼ����ֵ
    void show() { cout << start << " " << current << " " << count << endl; }
    void SetIterator(int a,int c){ start = a; count = c; }//��ֵ
    Order2 first(ConcreteAggregate* list);
    Order2 now(ConcreteAggregate* list);
    Order2 next(ConcreteAggregate* list);//��Ҫ�ж��Ƿ������һ��
    Order2 end(ConcreteAggregate* list);
    bool isEmpty(ConcreteAggregate* list);//��Ҫ�ж��Ƿ�Ϊ�գ���Ϊ�ղ��ܹ��鿴
private:
    int start;      //id��ʼ��λ��
    int current;  //��ǰλ��
    int count;  //����ͳ�Ƶĸ�������
};

//����ۺ���
class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate(vector<Order2>* v):list(*v) {};
    ~ConcreteAggregate() {};
    void showHtoT();//��ͷ��β����
    void showTtoH();//��β��ͷ����
    vector<Order2> GetIte() {
        return this->list;
    }
    void InfoUpgrate(int nowDay);//��������Ϣ����
    bool addOrder(int currentDay, int id,int now_day);//����µĶ���
    int deleteOrder();//ɾ��ָ���Ķ���
    Order2 GetOrder(int id);//��ȡָ����id�Ķ���
    int getSize();//��ȡ����
    void createIterator(ConcreteIterator* i,int start);//�������������
private:
    vector<Order2> list;
    //�����洢Order��list������,ÿ�β���һ����������Ҫ���뵽list
};



