/*
   Visitor.h -- defination
*/

#include "Visitor.h"
#include <iostream>
using namespace std;

/*
   函数：StateVisitor::visit
   参数：IdleState& idle
   功能：访问Idle状态
*/
void StateVisitor::visit(IdleState &idle)
{
	cout << "\nStateVisitor : visit(IdleState& idle) : The device state is " << idle.getState() << ".  Don't need repair." << endl;
}

/*
   函数：StateVisitor::visit
   参数：RunningState& running
   功能：访问Running状态
*/
void StateVisitor::visit(RunningState &running)
{
	cout << "\nStateVisitor : visit(RunningState &running) : The device state is " << running.getState() << ".  Running it." << endl;
}

/*
   函数：StateVisitor::visit
   参数：DamageState& damage
   功能：访问Damage状态
*/
void StateVisitor::visit(DamageState &damage)
{
	cout << "\nStateVisitor : visit(DamageState &damage) : The device state is " << damage.getState() << ".  Repairing it." << endl;
}
