/*
   Context.h -- defination
*/

#include <iostream>
#include "Context.h"
using namespace std;

// 构造函数
Context::Context()
{
	m_state = new IdleState();
}

// 析构函数
Context::~Context()
{
	delete m_state;
}

/*
   函数：Context::changeState
   参数：State* st
   功能：将设备状态改为st
*/
void Context::changeState(State2 *st)
{
	m_state = st;
}

/*
   函数：Context::request
   参数：
   功能：调用State中的handle方法对设备状态进行处理
*/
void Context::request()
{
	m_state->handle(*this);
}