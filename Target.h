
#ifndef TARGET_H
#define TARGET_H

/*
 * Target
 * defines specific interface that Client uses
 */
class Target
{
public:
    virtual ~Target() {}

    virtual void request() = 0;
    // ...
};

#endif // !TARGET_H
#pragma once