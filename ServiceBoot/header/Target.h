#ifndef TARGET_H
#define TARGET_H

/*
* ʵ��ģʽ��Adapter Pattern
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
    * Function:���麯���ӿڣ�������ʵ�ֽ���������
    */
    virtual void request() = 0;
    // ...
};

#endif // !TARGET_H
#pragma once