#pragma once

/*
* 实现模式：状态模式
*/

#include"header.h"
#include"canclass.h"//含有每个罐头的生产所需时间
#include"grouping_packaging.h"//含有套餐的信息，比如需要的罐头数量，
using namespace std;
class Order2;//订单
class State {//状态
public:
	int stateNum;
	virtual void Creation() {}//订单创建
	virtual void Inprogress() {}//订单进行中
	virtual void End() {}//订单结束
	virtual void CurrentState(Order2* order) {}//当前状态
};

class Order2//订单类
{
private:
	int id;//订单号，方便迭代器模式的实现，每一个订单的订单号都独一无二
	/// <summary>
	/// 获取订单的所需要的各种罐头的数量以及对应库存的存储量以及生产周期，然后计算需要的时间，
	/// 对于时间而言需要一天的时间来先把订单创建再开始生产，生产完成之后需要一天进行运输完成订单。
	/// </summary>
	State* state;  //当前的状态，创建、进行、结束
	int current_day;//当前时间
	int day;      //订单完成所需要的时间
public:
	Order2(State* state,int now_day) : state(state), day(0),current_day(now_day) {}//构造函数，订单id暂时未考虑
	~Order2() {}//析构函数
	int SumDays();//计算订单执行所需要的时间
	int GetDay() { return day; }//获取private变量day的值
	int GetID() { return id; }//返回订单的id
	int GetCurrentay() { return current_day; }//获取private变量current_day的值
	void SetID(int id) { this->id = id; }
	void SetCurrentay(int current_day) { this->current_day = current_day; }//赋值day
	void SetState(State* state) { delete this->state; this->state = state; } //状态赋值
	void GetState() { this->state->CurrentState(this); }//状态更新
	void ShowState();//输出状态
};
//订单结束
class EndState : public State//结束的状态类
{
public:
	void End(Order2* order) //订单结束
	{
		stateNum = 2;
	}
	void CurrentState(Order2* order) { End(order); }
	
};

//订单进行中
class InprogressState : public State//进行中的状态类具体
{
public:
	void Inprogress(Order2* order) //订单进行中
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
//订单创建
class CreationState : public State//订单创建开始
{
public:
	void Prophase(Order2* order)  //订单开始
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