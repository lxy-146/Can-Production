#include"NullObject.h"
int main()
{
	AbstractBuyer* b1 = BuyerFactory::getBuyer("WalMart");
	AbstractBuyer* b2 = BuyerFactory::getBuyer("Carrefour");
	AbstractBuyer* b3 = BuyerFactory::getBuyer("Hualian");
	AbstractBuyer* b4 = BuyerFactory::getBuyer("Darunfa");
	AbstractBuyer* b5 = BuyerFactory::getBuyer("Wumei");

	cout << "WalMart: " << b1->getName() << endl;
	cout << "Carrefour: " << b2->getName() << endl;
	cout << "Hualian: " << b3->getName() << endl;
	cout << "Darunfa: " << b4->getName() << endl;
	cout << "Wumei: " << b5->getName() << endl;

	delete b1;b1 = NULL;
	delete b2;b2 = NULL;
	delete b3;b3 = NULL;
	delete b4;b4 = NULL;
	delete b5;b5 = NULL;
	cout << endl;
	return 0;
}