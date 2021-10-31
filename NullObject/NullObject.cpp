/*
* NullObject.h-definition
*/
#include"NullObject.h"
int main()
{
	AbstractBuyer* b1 = BuyerFactory::getBuyer("WalMart");
	AbstractBuyer* b2 = BuyerFactory::getBuyer("Carrefour");
	AbstractBuyer* b3 = BuyerFactory::getBuyer("Hualian");
	AbstractBuyer* b4 = BuyerFactory::getBuyer("Darunfa");
	AbstractBuyer* b5 = BuyerFactory::getBuyer("Wumei");
	//创建采购商
	cout << "WalMart: " << b1->getName() << endl;
	cout << "Carrefour: " << b2->getName() << endl;
	cout << "Hualian: " << b3->getName() << endl;
	cout << "Darunfa: " << b4->getName() << endl;
	cout << "Wumei: " << b5->getName() << endl;
	//使用采购商对象中函数getName来确定是否在清单上
	delete b1;b1 = NULL;
	delete b2;b2 = NULL;
	delete b3;b3 = NULL;
	delete b4;b4 = NULL;
	delete b5;b5 = NULL;
	//安全删除所有指针
	cout << endl;
	return 0;
}