/*
* EquipmentBoot.h - Definition
*/

#include "EquipmentBoot.h"


/*
* Function:EquimentÆô¶¯º¯Êý
*/
void EquipmentBoot::Boot()
{
	std::cout << std::endl;
	std::cout << "=====Power Vertification ON !====" << std::endl;
	PowerVertificationOn();
	std::cout << "=====Equipment Manager ON !====" << std::endl;
	EquipmentManagerOn();
	std::cout << "=====Equipment ON !====" << std::endl;
	EquipmentOn();
	std::cout << "=====Equipment Adapter ON !====" << std::endl;
	EquipmentAdapterOn();
	std::cout << "=====BlackBoard ON !====" << std::endl;
	BlackBoardOn();
	std::cout << "=====Equipment START !====" << std::endl;
	equipment.start();
	std::cout << std::endl;
	std::cout << "=====CAN PRODUCTION BEGIN !====" << std::endl << std::endl;
}

/*
* Function:Interpreter Pattern
*/
void EquipmentBoot::PowerVertificationOn()
{
	std::cout << std::endl;
	std::shared_ptr<ContextInterpreter> bus = std::make_shared<ContextInterpreter>();
	std::vector<std::string> equipments = { "Meat Processor" , "Vegetable Processor" , "Fruit Processor" , "Meat Productor" , "Vegetable Productor" , "Fruit Productor" };
	for (std::string equipment : equipments)
	{
		bus->IsFree(equipment);
	}
	std::cout << std::endl;
}

/*
* Function:Lazy Initialization Pattern
*/
void EquipmentBoot::EquipmentManagerOn()
{
	std::cout << std::endl;
	EquipmentManager::getManager("Meat Processor Manager");
	EquipmentManager::printCurrentTypes();

	EquipmentManager::getManager("Vegetable Processor Manager");
	EquipmentManager::printCurrentTypes();

	// returns pre-existing instance from first 
	EquipmentManager::getManager("Vegetable Processor Manager");
	EquipmentManager::printCurrentTypes();
	std::cout << std::endl;
}

/*
* Function:Facade Pattern
*/
void EquipmentBoot::EquipmentOn()
{
	Equipment equipment;
	equipment.start();

	std::cout << std::endl << "=====Client do something else !====" << std::endl;

	equipment.shutdown();

}

/*
* Function:Adapter Pattern
*/
void EquipmentBoot::EquipmentAdapterOn()
{
	std::cout << std::endl;
	EquipmentClassAdapterOn();
	EquipmentObjectAdapterOn();
	std::cout << std::endl;
}

/*
* Function:Adapter Pattern
*/
void EquipmentBoot::EquipmentClassAdapterOn()
{
	std::cout << std::endl;
	Target* t = new EquipmentClassAdapter();
	t->request();
	delete t;
	std::cout << std::endl;
}

/*
* Function:Adapter Pattern
*/
void EquipmentBoot::EquipmentObjectAdapterOn()
{
	std::cout << std::endl;
	Target* t = new EquipmentObjectAdapter();
	t->request();
	delete t;
	std::cout << std::endl;
}

/*
* Function:BlackBoard Pattern
*/
void EquipmentBoot::BlackBoardOn()
{
	std::cout << std::endl;
	BlackBoard blockBoard;
	blockBoard.setValue("NO.1 Meat Productor needs to be repaired", true);
	blockBoard.setValue("NO.2 Meat Productor needs to be repaired", false);
	blockBoard.setValue("NO.1 Vegetable Productor needs to be repaired", false);
	blockBoard.setValue("NO.2 Vegetable Productor needs to be repaired", true);

	blockBoard.showBlackBoard();
	std::cout << std::endl;
}