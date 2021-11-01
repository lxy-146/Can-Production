#pragma once
#include"header.h"

/*
* ʵ��ģʽ���н���ģʽ
*/

//����ͬ����
class Colleague;
//�����н���
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
   ������Colleague::send
   ������string msg
   ���ܣ�������Ϣ
	*/
	virtual void send(std::string msg) = 0;
	/*
   ������Colleague::send
   ������string msg
   ���ܣ�ȷ�Ͻ�����Ϣ
	*/
	virtual void notify(std::string msg) = 0;
};
//����ͬ����0->�˿�
class ConcreteColleague_0 : public Colleague
{
public:
	ConcreteColleague_0(Mediator* p) : Colleague(p) {}
	/*
   ������ConcreteColleague_0::send
   ������string msg
   ���ܣ�������Ϣ
	*/
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
	/*
   ������ConcreteColleague_0::notify
   ������string msg
   ���ܣ�ȷ���յ���Ϣ
	*/
	void notify(std::string msg)
	{
		std::cout << "Colleague_0 �յ�����Ϣ��" << msg << std::endl;
	}
};
//����ͬ����1->����ͷ��
class ConcreteColleague_1 : public Colleague
{
public:
	ConcreteColleague_1(Mediator* p) : Colleague(p) {}
	/*
   ������ConcreteColleague_1::send
   ������string msg
   ���ܣ�������Ϣ
	*/
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
	/*
   ������ConcreteColleague_1::notify
   ������string msg
   ���ܣ�ȷ���յ���Ϣ
	*/
	void notify(std::string msg)
	{
		std::cout << "Colleague_1 �յ�����Ϣ��" << msg << std::endl;
	}
};
//�����н���
class ConcreteMediator : public Mediator
{
private:
	// ����Ҳ������һ���б�
	Colleague* m_p1;
	Colleague* m_p2;
public:
	/*
   ������ConcreteMediator::addColleague
   ������Colleague* p1, Colleague* p2
   ���ܣ����������������Ϣ������
	*/
	void addColleague(Colleague* p1, Colleague* p2)
	{
		m_p1 = p1;
		m_p2 = p2;
	}
	/*
   ������ConcreteMediator::send
   ������std::string msg, Colleague* p
   ���ܣ������������һ��ͬ�·���������Ϣ������Ӧ�ø�˭Ҫ����������
		 ������һ���ܼ򵥵�Ӧ�á���������ܿ��������������С�
		 һ�������ǿͻ���һ�������ǿͷ�
	*/
	void send(std::string msg, Colleague* p)
	{
		
		if (p == m_p1)
			m_p2->notify(msg);
		else
			m_p1->notify(msg);
	}
};
