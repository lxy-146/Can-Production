#pragma once

#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "ConcreteEquipment.h"

class Equipment {

public:

	void specificRequest();
	void start();

	void shutdown();

private:
	//私有，屏蔽子系统
	Host m_host;
	LCDDisplay m_display;
	std::shared_ptr<Peripheral> m_pPeripheral = std::make_shared<Peripheral>();
};

#endif // !EQUIPMENT_H
#pragma once