#ifndef TARGET_H
#define TARGET_H

/*
* 实现模式：Adapter Pattern
*/

/*
 * Target
 * defines specific interface that Client uses
 */
class Target
{
public:
    virtual ~Target() {}

    /*
    * Function:纯虚函数接口，由子类实现接收请求功能
    */
    virtual void request() = 0;
    // ...
};

#endif // !TARGET_H
#pragma once