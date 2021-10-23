#include"header.h"
#include"factory.h"

AbstractFactory* FactoryProducer::getFactory(string fac) {
	if (fac == "packedge" || fac == "Packedge" || fac == "PACKEDGE") {
		return new PackedgeFactory();
	}
	else if (fac == "kind" || fac == "Kind" || fac == "KIND") {
		return new KindFactory();
	}
}

Packedge* PackedgeFactory::getPackedge(string a) {
	if (a == "Big" || a == "big" || a == "BIG") {
		return new BigJar();
	}
	else if (a == "Little" || a == "little" || a == "LITTLE") {
		return new LittleJar();
	}
}

Kind* PackedgeFactory::getKind(string a) {
	cout << "i can't do this" << endl;
	return nullptr;
}

Kind* KindFactory::getKind(string a) {
	if (a == "Fruit" || a == "fruit" || a == "FRUIT") {
		return new FruitIn();
	}
	else if (a == "Meat" || a == "meat" || a == "MEAT") {
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
	cout << "processing fruit" << endl;
}

void MeatIn::make() {
	cout << "processing meat" << endl;
}