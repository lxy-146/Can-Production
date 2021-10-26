#ifndef CODE_VISITOR_H
#define CODE_VISITOR_H
#include"State.h"

class IdleState;
class RunningState;
class DamageState;

// 父类Visitor
class Visitor
{
public:
	// 对于不同的状态调用不同的visit方法，由子类去实现
	virtual void visit(IdleState& idle) = 0;
	virtual void visit(RunningState& RunningState) = 0;
	virtual void visit(DamageState& damage) = 0;
	Visitor() {};
	~Visitor() {};
};

// 具体的Visitor
class StateVisitor :public Visitor
{
public:
	virtual void visit(IdleState& idle) override;
	virtual void visit(RunningState& RunningState) override;
	virtual void visit(DamageState& damage) override;
	StateVisitor() {};
	~StateVisitor() {};
};
#endif
