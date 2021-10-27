#include"header.h"
#include"factory.h"

AbstractFactory* FactoryProducer::getFactory(string fac) {
	if (fac == "packedge" || fac == "Packedge" || fac == "PACKEDGE") {
		cout << "produce packedge factory" << endl;
		return new PackedgeFactory();
	}
	else if (fac == "kind" || fac == "Kind" || fac == "KIND") {
		cout << "produce kind factory" << endl;
		return new KindFactory();
	}
}

Packedge* PackedgeFactory::getPackedge(string a) {
	if (a == "Big" || a == "big" || a == "BIG") {
		cout << "produce big jar factory" << endl;
		return new BigJar();
	}
	else if (a == "Little" || a == "little" || a == "LITTLE") {
		cout << "produce small jar factory" << endl;
		return new LittleJar();
	}
}

Kind* PackedgeFactory::getKind(string a) {
	cout << "i can't do this" << endl;
	return nullptr;
}

Kind* KindFactory::getKind(string a) {
	if (a == "Fruit" || a == "fruit" || a == "FRUIT") {
		cout << "produce fruit factory" << endl;
		return new FruitIn();
	}
	else if (a == "Meat" || a == "meat" || a == "MEAT") {
		cout << "produce meat factory" << endl;
		return new MeatIn();
	}
}

Packedge* KindFactory::getPackedge(string a) {
	cout << "i can't do this" << endl;
	return nullptr;
}

void BigJar::make() {
	cout << "produce a big jar" << endl;
}

void LittleJar::make() {
	cout << "produce a little jar" << endl;
}

void FruitIn::make() {
	cout << "produce fruit" << endl;
}

void MeatIn::make() {
	cout << "produce meat" << endl;
}