#ifndef EQUIPMENT_CLASS_ADAPTER_H
#define EQUIPMENT_CLASS_ADAPTER_H

#include "Equipment.h"
#include "Target.h"

/*
 * Adaptee
 * all requests get delegated to the Adaptee which defines
 * an existing interface that needs adapting
 */


 /*
  * Adapter
  * implements the Target interface and lets the Adaptee respond
  * to request on a Target by extending both classes
  * ie adapts the interface of Adaptee to the Target interface
  */
class EquipmentClassAdapter : public Target, private Equipment
{
public:
    virtual void request()
    {
        std::cout << "EquipmentClassAdapter is called" << std::endl;
        specificRequest();
    }
    // ...
};

#endif // !EQUIPMENT_CLASS_ADAPTER_H
#pragma once