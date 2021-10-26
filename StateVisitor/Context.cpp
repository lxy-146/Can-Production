#include<iostream>
#include"Context.h"
using namespace std;

Context::Context()
{
	m_state = new IdleState();
}

Context::~Context()
{
	delete m_state;
}

void Context::changeState(State2* st)
{
	m_state = st;
}

void Context::request()  
{
	m_state->handle(*this);
}