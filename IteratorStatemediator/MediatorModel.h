#pragma once
#include"header.h"

/*
* 实现模式：中介者模式
*/

//抽象同事类
class Colleague;
//抽象中介类
class Mediator
{
public:
	virtual void send(std::string  msg, Colleague* p) = 0;
};

class Colleague
{
protected:
	Mediator* m_mediator;
public:
	Colleague(Mediator* p)
	{
		m_mediator = p;
	}
	/*
   函数：Colleague::send
   参数：string msg
   功能：发送消息
	*/
	virtual void send(std::string msg) = 0;
	/*
   函数：Colleague::send
   参数：string msg
   功能：确认接受消息
	*/
	virtual void notify(std::string msg) = 0;
};
//具体同事类0->顾客
class ConcreteColleague_0 : public Colleague
{
public:
	ConcreteColleague_0(Mediator* p) : Colleague(p) {}
	/*
   函数：ConcreteColleague_0::send
   参数：string msg
   功能：发送消息
	*/
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
	/*
   函数：ConcreteColleague_0::notify
   参数：string msg
   功能：确认收到消息
	*/
	void notify(std::string msg)
	{
		std::cout << "Colleague_0 收到了消息：" << msg << std::endl;
	}
};
//具体同事类1->卖罐头的
class ConcreteColleague_1 : public Colleague
{
public:
	ConcreteColleague_1(Mediator* p) : Colleague(p) {}
	/*
   函数：ConcreteColleague_1::send
   参数：string msg
   功能：发送消息
	*/
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
	/*
   函数：ConcreteColleague_1::notify
   参数：string msg
   功能：确认收到消息
	*/
	void notify(std::string msg)
	{
		std::cout << "Colleague_1 收到了消息：" << msg << std::endl;
	}
};
//具体中介者
class ConcreteMediator : public Mediator
{
private:
	// 这里也可以是一个列表
	Colleague* m_p1;
	Colleague* m_p2;
public:
	/*
   函数：ConcreteMediator::addColleague
   参数：Colleague* p1, Colleague* p2
   功能：加入两个具体的信息交流者
	*/
	void addColleague(Colleague* p1, Colleague* p2)
	{
		m_p1 = p1;
		m_p2 = p2;
	}
	/*
   函数：ConcreteMediator::send
   参数：std::string msg, Colleague* p
   功能：这里接受来自一个同事发过来的消息，具体应该给谁要根据需求来
		 这里是一个很简单的应用。比如该类总可以是有两个队列。
		 一个队列是客户，一个队列是客服
	*/
	void send(std::string msg, Colleague* p)
	{
		
		if (p == m_p1)
			m_p2->notify(msg);
		else
			m_p1->notify(msg);
	}
};
