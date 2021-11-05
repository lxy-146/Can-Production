/*
* EquipmentBoot.h - Definition
*/

#include "EquipmentBoot.h"


/*
* Function:Equiment启动函数
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
*			生产设备验证，判断将要启动的Equipment是否被支持，
*			生产设备名称在验证成功后即可启动。
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
*			生产设备管理员的延迟初始化，当生产设备管理员多次被初始化时，将会返回
*			生产设备管理员第一次被初始化时的已经存在的实例
*/
void EquipmentBoot::EquipmentManagerOn()
{
	std::cout << std::endl;
	EquipmentManager::getManager("Meat Processor Manager");
	EquipmentManager::printCurrentTypes();

	EquipmentManager::getManager("Fruit Processor Manager");
	EquipmentManager::printCurrentTypes();

	// returns pre-existing instance from first 
	EquipmentManager::getManager("Fruit Processor Manager");
	EquipmentManager::printCurrentTypes();
	std::cout << std::endl;
}

/*
* Function:Facade Pattern
*			生产设备启动，客户端通过调用生产设备启动接口，生产设备内部子系统会依次启动
*			而客户端只关心生产设备开机、关机的过程，并不需要了解生产设备内部子系统的启动过程。
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
*			适配器接收客户端的请求，适配器调用生产设备的特例方法。
*			通过两层传递，实现了生产设备处理请求的适配
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
*			类适配器，通过私有继承生产设备的处理请求方法，以达到适配的目的
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
*			对象适配器，通过内部拥有一个生产设备成员对象，以调用处理请求的特例方法，
*			达到适配的目的
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
*			黑板模式，存储罐头生产设备中的维修信息。生产设备管理员可以查看
			在黑板中存储的维修信息，并对生产设备做相应的处理。黑板支持写入，读出，
			展示黑板所有信息等操作。
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