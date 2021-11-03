/*
  实现模式：状态模式
*/

#ifndef CODE_CONTEXT_H
#define CODE_CONTEXT_H

#include "State.h"

class State2;
//与状态模式交互的类
class Context
{
private:
	State2 *m_state;

public:
	Context();
	~Context();

	void changeState(State2 *st);
	void request();
};
#endif