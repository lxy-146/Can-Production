#include "EquipmentBoot.h"



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


void EquipmentBoot::EquipmentManagerOn()
{
	std::cout << std::endl;
	EquipmentManager::getManager("Meat Processor Manager");
	EquipmentManager::printCurrentTypes();

	EquipmentManager::getManager("Vegetable Processor Manager");
	EquipmentManager::printCurrentTypes();

	// returns pre-existing instance from first 
	// time Fruit with "Vegetable Processor Manager" was created
	EquipmentManager::getManager("Vegetable Processor Manager");
	EquipmentManager::printCurrentTypes();
	std::cout << std::endl;
}


void EquipmentBoot::EquipmentOn()
{
	Equipment equipment;
	equipment.start();

	std::cout << std::endl << "=====Client do something else !====" << std::endl;

	equipment.shutdown();

}


void EquipmentBoot::EquipmentAdapterOn()
{
	std::cout << std::endl;
	EquipmentClassAdapterOn();
	EquipmentObjectAdapterOn();
	std::cout << std::endl;
}


void EquipmentBoot::EquipmentClassAdapterOn()
{
	std::cout << std::endl;
	Target* t = new EquipmentClassAdapter();
	t->request();
	delete t;
	std::cout << std::endl;
}


void EquipmentBoot::EquipmentObjectAdapterOn()
{
	std::cout << std::endl;
	Target* t = new EquipmentObjectAdapter();
	t->request();
	delete t;
	std::cout << std::endl;
}


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

//int main()
//{
//	EquipmentBoot equipmentBoot;
//	equipmentBoot.Boot();
//
//	system("pause");
//	return 0;
//}