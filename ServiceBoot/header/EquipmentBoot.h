#ifndef EQUIPMENT_BOOT_H
#define EQUIPMENT_BOOT_H

/*
* Equipment∆Ù∂Ø¿‡
*/

#include "PowerVertification.h"
#include "EquipmentManager.h"
#include "Equipment.h"
#include "EquipmentClassAdapter.h"
#include "EquipmentObjectAdapter.h"
#include "BlackBoard.h"

class EquipmentBoot
{
public:
	EquipmentBoot() {};
	~EquipmentBoot() {};
	void Boot();
private:
	void PowerVertificationOn();
	void EquipmentManagerOn();
	void EquipmentOn();
	void EquipmentAdapterOn();
	void EquipmentClassAdapterOn();
	void EquipmentObjectAdapterOn();
	void BlackBoardOn();
private:
	Equipment equipment;
};

#endif // !EQUIPMENT_BOOT_H
#pragma once
