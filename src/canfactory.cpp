#include "canfactory.h"
#include "header.h"

can_factory* can_factory::canfactory = nullptr;

can_factory* can_factory::GetInstance() {
	if (canfactory == nullptr)
	{
		canfactory = new can_factory();
		cout << "canfactory is established" << endl;
	}
	return canfactory;
}