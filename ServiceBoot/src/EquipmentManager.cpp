/*
* EquipmentManager.h - Definition
*/

#include "EquipmentManager.h"

//definition needed for using any static member variable
std::map<std::string, EquipmentManager*> EquipmentManager::types;

/*
 * Lazy Factory method, gets the EquipmentManager instance associated with a
 * certain type. Instantiates new ones as needed.
 * precondition: type. Any string that describes a EquipmentManager type, e.g. "Meat Processor Manager"
 * postcondition: The EquipmentManager instance associated with that type.
 */
EquipmentManager* EquipmentManager::getManager(const std::string& type) {
    EquipmentManager*& f = types[type];   // try to find a pre-existing instance, or std::map'll create one if not found

    if (!f) {                   // if it was created by map automatically, it'll be pointing to NULL
        // couldn't find one, so make a new instance
        f = new EquipmentManager(type); // lazy initialization part
    }
    return f;
}

/*
 * For example purposes to see pattern in action
 */
void EquipmentManager::printCurrentTypes() {
    if (!types.empty()) {
        std::cout << "Number of instances made = " << types.size() << std::endl;
        for (std::map<std::string, EquipmentManager*>::iterator iter = types.begin(); iter != types.end(); ++iter) {
            std::cout << (*iter).first << std::endl;
        }
        std::cout << std::endl;
    }
}