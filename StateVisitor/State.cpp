#include "State.h"
#include <iostream>
using namespace std;

// state in idle
void IdleState::accept(Visitor& visitor)
{
	visitor.visit(*this);
}

void IdleState::handle(Context& c)
{
	RunningState* r = new RunningState();
	cout << "Now in handle method.\n"
		<< "We open the device now.\n"
		<< "The device state is changed to " << r->getState() << "." << endl;
	// 将设备的状态从Idle改为Running
	c.changeState(r);
}

// state in running
void RunningState::accept(Visitor& visitor)
{
	visitor.visit(*this);
}

void RunningState::handle(Context& c)
{
	DamageState* d = new DamageState();
	cout << "Now in handle method.\n"
		<< "There are some damages in device.\n"
		<< "The device state is changed to " << d->getState() << "." << endl;
	// 将设备的状态从Running改为Damage
	c.changeState(d);
}

// state in damage
void DamageState::accept(Visitor& visitor)
{
	visitor.visit(*this);
}

void DamageState::handle(Context& c)
{
	IdleState* i = new IdleState();
	cout << "Now in handle method.\n"
		<< "We repair it now.\n"
		<< "The device state is changed to " << i->getState() << "." << endl;
	// 将设备的状态从Damage改为Idle
	c.changeState(i);
}
