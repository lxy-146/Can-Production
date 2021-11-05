/*
* EquipmentBoot.h - Definition
*/

#include "EquipmentBoot.h"


/*
* Function:Equiment��������
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
*			�����豸��֤���жϽ�Ҫ������Equipment�Ƿ�֧�֣�
*			�����豸��������֤�ɹ��󼴿�������
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
*			�����豸����Ա���ӳٳ�ʼ�����������豸����Ա��α���ʼ��ʱ�����᷵��
*			�����豸����Ա��һ�α���ʼ��ʱ���Ѿ����ڵ�ʵ��
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
*			�����豸�������ͻ���ͨ�����������豸�����ӿڣ������豸�ڲ���ϵͳ����������
*			���ͻ���ֻ���������豸�������ػ��Ĺ��̣�������Ҫ�˽������豸�ڲ���ϵͳ���������̡�
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
*			���������տͻ��˵��������������������豸������������
*			ͨ�����㴫�ݣ�ʵ���������豸�������������
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
*			����������ͨ��˽�м̳������豸�Ĵ������󷽷����Դﵽ�����Ŀ��
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
*			������������ͨ���ڲ�ӵ��һ�������豸��Ա�����Ե��ô������������������
*			�ﵽ�����Ŀ��
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
*			�ڰ�ģʽ���洢��ͷ�����豸�е�ά����Ϣ�������豸����Ա���Բ鿴
			�ںڰ��д洢��ά����Ϣ�����������豸����Ӧ�Ĵ����ڰ�֧��д�룬������
			չʾ�ڰ�������Ϣ�Ȳ�����
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