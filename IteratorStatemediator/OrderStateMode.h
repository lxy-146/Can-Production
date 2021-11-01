#pragma once

/*
* ʵ��ģʽ��״̬ģʽ
*/

#include"header.h"
#include"canclass.h"//����ÿ����ͷ����������ʱ��
#include"grouping_packaging.h"//�����ײ͵���Ϣ��������Ҫ�Ĺ�ͷ������
using namespace std;
class Order2;//����
class State {//״̬
public:
	int stateNum;
	virtual void Creation() {}//��������
	virtual void Inprogress() {}//����������
	virtual void End() {}//��������
	virtual void CurrentState(Order2* order) {}//��ǰ״̬
};

class Order2//������
{
private:
	int id;//�����ţ����������ģʽ��ʵ�֣�ÿһ�������Ķ����Ŷ���һ�޶�
	/// <summary>
	/// ��ȡ����������Ҫ�ĸ��ֹ�ͷ�������Լ���Ӧ���Ĵ洢���Լ��������ڣ�Ȼ�������Ҫ��ʱ�䣬
	/// ����ʱ�������Ҫһ���ʱ�����ȰѶ��������ٿ�ʼ�������������֮����Ҫһ�����������ɶ�����
	/// </summary>
	State* state;  //��ǰ��״̬�����������С�����
	int current_day;//��ǰʱ��
	int day;      //�����������Ҫ��ʱ��
public:
	Order2(State* state,int now_day) : state(state), day(0),current_day(now_day) {}//���캯��������id��ʱδ����
	~Order2() {}//��������
	int SumDays();//���㶩��ִ������Ҫ��ʱ��
	int GetDay() { return day; }//��ȡprivate����day��ֵ
	int GetID() { return id; }//���ض�����id
	int GetCurrentay() { return current_day; }//��ȡprivate����current_day��ֵ
	void SetID(int id) { this->id = id; }
	void SetCurrentay(int current_day) { this->current_day = current_day; }//��ֵday
	void SetState(State* state) { delete this->state; this->state = state; } //״̬��ֵ
	void GetState() { this->state->CurrentState(this); }//״̬����
	void ShowState();//���״̬
};
//��������
class EndState : public State//������״̬��
{
public:
	void End(Order2* order) //��������
	{
		stateNum = 2;
	}
	void CurrentState(Order2* order) { End(order); }
	
};

//����������
class InprogressState : public State//�����е�״̬�����
{
public:
	void Inprogress(Order2* order) //����������
	{
		if (order->GetCurrentay() < order->GetDay())
		{
			stateNum = 1;
		}
		else
		{
			order->SetState(new EndState());
			order->GetState();
		}
	}
	void CurrentState(Order2* order) { Inprogress(order); }
};
//��������
class CreationState : public State//����������ʼ
{
public:
	void Prophase(Order2* order)  //������ʼ
	{
		if (order->GetCurrentay() <= 1)
		{
			stateNum = 0;
		}
		else
		{
			order->SetState(new InprogressState());
			order->GetState();
		}
	}
	void CurrentState(Order2* order) { Prophase(order); }
};