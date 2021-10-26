#ifndef CODE_STATE_H
#define CODE_STATE_H
#include <string>
#include"Visitor.h"
#include"Context.h"
#include<vector>

class Context;
class Visitor;
class State2
{
protected:
	std::string state;
	State2()
	{

	};
public:
	// 由visitor进行访问
	virtual void accept(Visitor& visitor) = 0;
	// 对不同的状态进行不同的处理
	virtual void handle(Context& c) = 0;
	
	~State2() {};
	std::string getState()
	{
		return state;
	}
};

class IdleState : public State2
{
public:
	virtual void accept(Visitor& visitor);
	virtual void handle(Context& c);
	IdleState()
	{
		state = "idle";
	};
	~IdleState() {};
};

class RunningState : public State2
{
public:
	virtual void accept(Visitor& visitor);
	virtual void handle(Context& c);
	RunningState()
	{
		state = "running";
	};
	~RunningState() {};
};

class DamageState : public State2
{
public:
	virtual void accept(Visitor& visitor);
	virtual void handle(Context& c);
	DamageState() 
	{
		state = "damage";
	};
	~DamageState() {};
};

#endif 
