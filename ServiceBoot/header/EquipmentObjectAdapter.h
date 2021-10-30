#ifndef EQUIPMENT_OBJECT_ADAPTER_H
#define EQUIPMENT_OBJECT_ADAPTER_H

/*
* 实现模式：Adapter Pattern
*/

#include "Target.h"
#include "Equipment.h"


/*
 * Adaptee
 * defines an existing interface that needs adapting and thanks
 * to Adapter it will get calls that client makes on the Target
 *
 */

 /*
  * Adapter
  * implements the Target interface and when it gets a method call it
  * delegates the call to a Adaptee
  */
class EquipmentObjectAdapter : public Target
{
public:
    EquipmentObjectAdapter() : equipment() {}

    ~EquipmentObjectAdapter()
    {
        delete equipment;
    }

    /*
    * Function: 对象适配器接收请求，通过类中的成员变量(对象)
    *           Equipment调用specificRequest()实现对Equipment的适配
    */
    void request()
    {
        std::cout << "EquipmentObjectAdapter is called" << std::endl;
        equipment->specificRequest();
        // ...
    }
    // ...

private:
    Equipment* equipment;
    // ...
};

#endif // !EQUIPMENT_OBJECT_ADAPTER_H
#pragma once