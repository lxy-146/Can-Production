#include "Visitor.h"
#include <iostream>
using namespace std;

void StateVisitor::visit(IdleState& idle)
{
	cout << "\nNow in visit method." << endl;
	cout << "The device state is " << idle.getState() << ".  Don't need repair." << endl;
}

void StateVisitor::visit(RunningState& running)
{
	cout << "\nNow in visit method." << endl;
	cout << "The device state is " << running.getState() << ".  Running it." << endl;
}

void StateVisitor::visit(DamageState& damage)
{
	cout << "\nNow in visit method." << endl;
	cout << "The device state is " << damage.getState() << ".  Repairing it." << endl;
}
