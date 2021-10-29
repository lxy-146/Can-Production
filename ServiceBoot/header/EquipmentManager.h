#ifndef EQUIPMENT_MANAGER_H
#define EQUIPMENT_MANAGER_H

#include <iostream>
#include <string>
#include <map>

class EquipmentManager {
public:
    static EquipmentManager* getManager(const std::string& type);
    static void printCurrentTypes();

private:
    static std::map<std::string, EquipmentManager*> types;
    std::string type;

    // note: constructor private forcing one to use static getManager()
    EquipmentManager(const std::string& t) : type(t) {}
};

#endif // !EQUIPMENT_MANAGER_H
#pragma once