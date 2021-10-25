#pragma once
#include"header.h"

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
	virtual void send(std::string msg) = 0;
	virtual void notify(std::string msg) = 0;
};
//具体同事类0->顾客
class ConcreteColleague_0 : public Colleague
{
public:
	ConcreteColleague_0(Mediator* p) : Colleague(p) {}
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
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
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
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
	void addColleague(Colleague* p1, Colleague* p2)
	{
		m_p1 = p1;
		m_p2 = p2;
	}
	void send(std::string msg, Colleague* p)
	{
		// 这里接受来自一个同事发过来的消息，具体应该给谁要根据需求来
		// 这里是一个很简单的应用。比如该类总可以是有两个队列。
		// 一个队列是客户，一个队列是客服
		if (p == m_p1)
			m_p2->notify(msg);
		else
			m_p1->notify(msg);
	}
};
