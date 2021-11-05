/*
   State.h -- defination
*/

#include "State.h"
#include <iostream>
using namespace std;

/*
   函数：IdleState::accept
   参数：Visitor& visitor
   功能：Visitor模式，设备状态为Idle时接收一个Visitor参数，调用其visit函数
		 对设备状态进行访问
*/
void IdleState::accept(Visitor& visitor)
{
	visitor.visit(*this);
}

/*
   函数：IdleState::handle
   参数：Context& c
   功能：State模式，设备状态为Idle时接收一个Context参数，对设备当前状态进行
        操作，并将设备状态从Idle改为Running
*/
void IdleState::handle(Context& c)
{
	RunningState* r = new RunningState();
	cout << "IdleState:handle(Context& c):We open the device now.\n"
		 << "The device state is changed to " << r->getState() << "." << endl;
	// 将设备的状态从Idle改为Running
	c.changeState(r);
}

/*
   函数：RunningState::accept
   参数：Visitor& visitor
   功能：Visitor模式，设备状态为Running时接收一个Visitor参数，调用其visit函数
		 对设备状态进行访问
*/
void RunningState::accept(Visitor& visitor)
{
	visitor.visit(*this);
}


/*
   函数：RunningState::handle
   参数：Context& c
   功能：State模式，设备状态为Running时接收一个Context参数，对设备当前状态进行
		操作，并将设备状态从Running改为Damage
*/
void RunningState::handle(Context& c)
{
	DamageState* d = new DamageState();
	cout << "RunningState:handle(Context& c):There are some damages in device.\n"
		 << "The device state is changed to " << d->getState() << "." << endl;
	// 将设备的状态从Running改为Damage
	c.changeState(d);
}

/*
   函数：DamageState::accept
   参数：Visitor& visitor
   功能：Visitor模式，设备状态为Damage时接收一个Visitor参数，调用其visit函数
		 对设备状态进行访问
*/
void DamageState::accept(Visitor& visitor)
{
	visitor.visit(*this);
}

/*
   函数：RunningState::handle
   参数：Context& c
   功能：State模式，设备状态为Damage时接收一个Context参数，对设备当前状态进行
		操作，并将设备状态从Damage改为Idle
*/
void DamageState::handle(Context& c)
{
	IdleState* i = new IdleState();
	cout << "DamageState:handle(Context& c):We repair it now.\n"
		 << "The device state is changed to " << i->getState() << "." << endl;
	// 将设备的状态从Damage改为Idle
	c.changeState(i);
}
