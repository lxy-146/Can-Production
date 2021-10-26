#ifndef CODE_CONTEXT_H
#define CODE_CONTEXT_H

#include"State.h"

class State2;
class Context
{
private:
	State2* m_state;

public:
	Context();
	~Context();

	void changeState(State2* st);
	void request();
};
#endif