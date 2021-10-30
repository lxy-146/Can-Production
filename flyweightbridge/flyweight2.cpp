#include"flyweight2.h"

void MiddleCan::make() {
	kind->make();
	cout << "middle can" << endl;
}

void FishKind::make() {
	cout << "produce fish ";
}

void PorkKind::make() {
	cout << "produce pork ";
}

void BeefKind::make() {
	cout << "produce beef ";
}
Can* Factory::GetFlyweights(string key) {
	if (flyweights.count(key) == 0)
	{
		Can_pack* c;
		if (key == "bigfruit") c = new Big_Can(new FruitCan());
		else if (key == "smallfruit") c = new Small_Can(new FruitCan());
		else if (key == "bigmeat")c = new Big_Can(new MeatCan());
		else if (key == "smallmeat")c = new Small_Can(new MeatCan());
		flyweights.insert(make_pair(key, c));
	}
	return (Can*)flyweights[key];
}



