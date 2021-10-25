#pragma once
#include"header.h"

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
	virtual void send(std::string msg) = 0;
	virtual void notify(std::string msg) = 0;
};
//����ͬ����0->�˿�
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
		std::cout << "Colleague_0 �յ�����Ϣ��" << msg << std::endl;
	}
};
//����ͬ����1->����ͷ��
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
	void addColleague(Colleague* p1, Colleague* p2)
	{
		m_p1 = p1;
		m_p2 = p2;
	}
	void send(std::string msg, Colleague* p)
	{
		// �����������һ��ͬ�·���������Ϣ������Ӧ�ø�˭Ҫ����������
		// ������һ���ܼ򵥵�Ӧ�á���������ܿ��������������С�
		// һ�������ǿͻ���һ�������ǿͷ�
		if (p == m_p1)
			m_p2->notify(msg);
		else
			m_p1->notify(msg);
	}
};
