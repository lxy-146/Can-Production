/*
* factory.h-defination
*/

#include"header.h"
#include"factory.h"


/*
* ������ FactoryProducer::getFactory
* ������ string fac
* ���ܣ�ͨ��fac�����ݷ��ض�Ӧ���ܵĹ���
*/
AbstractFactory* FactoryProducer::getFactory(string fac) {
	if (fac == "package" || fac == "Package" || fac == "PACKAGE") {
		cout << "FactoryProducer:getFactory:produce package factory" << endl;
		return new PackageFactory();
	}
	else if (fac == "kind" || fac == "Kind" || fac == "KIND") {
		cout << "FactoryProducer:getFactory:produce kind factory" << endl;
		return new KindFactory();
	}
}
/*
* ������ PackageFactory::getPackage
* ������ string a
* ���ܣ� ͨ��a�����ݷ��ض�Ӧ�İ�װ��
*/
Package* PackageFactory::getPackage(string a) {
	if (a == "Big" || a == "big" || a == "BIG") {
		cout << "PackageFactory:getPackage:produce big jar object" << endl;
		return new BigJar();
	}
	else if (a == "Little" || a == "little" || a == "LITTLE") {
		cout << "PackageFactory:getPackage:produce small jar object" << endl;
		return new LittleJar();
	}
}
/*
* ������PackageFactory::getKind
* ������string a
* ���ܣ����û��������ʱ���ض�Ӧ��ʾ
*/
Kind* PackageFactory::getKind(string a) {
	cout << "i can't do this" << endl;
	return nullptr;
}
/*
* ������KindFactory::getKind
* ������string a
* ���ܣ�����a���ض�Ӧ��ȷ�������࣬���a��ˮ�����ͷ���FruitIn������ͷ���Meat
*/
Kind* KindFactory::getKind(string a) {
	if (a == "Fruit" || a == "fruit" || a == "FRUIT") {
		cout << "KindFactory:getKind:produce fruit object" << endl;
		return new FruitIn();
	}
	else if (a == "Meat" || a == "meat" || a == "MEAT") {
		cout << "KindFactory:getKind:produce meat object" << endl;
		return new MeatIn();
	}
}
/*
* ������KindFactory::getPackage
* ������string a
* ���ܣ����û��������ʱ���ض�Ӧ��ʾ
*/
Package* KindFactory::getPackage(string a) {
	cout << "i can't do this" << endl;
	return nullptr;
}
/*
* ������BigJar::make
* ������null
* ���ܣ�����һ�����ͷ��
*/
void BigJar::make() {
	cout << "BigJar:make:produce a big jar" << endl;
}
/*
* ������LittleJar::make
* ������null
* ���ܣ�����һ��С��ͷ��
*/
void LittleJar::make() {
	cout << "LittleJar:make:produce a little jar" << endl;
}
/*
* ������FruitIn::make
* ������null
* ���ܣ�����ˮ��
*/
void FruitIn::make() {
	cout << "FruitIn:make:produce fruit" << endl;
}
/*
* ������MeatIn::make
* ������null
* ���ܣ�������
*/
void MeatIn::make() {
	cout << "MeatIn:make:produce meat" << endl;
}
/*
* ������BigJar::unmake
* ������null
* ���ܣ�����һ�����ͷ��
*/
void BigJar::unmake() {
	cout << "distroy a big jar" << endl;
}
/*
* ������LittleJar::unmake
* ������null
* ���ܣ�����һ��С��ͷ��
*/
void LittleJar::unmake() {
	cout << "distroy a little jar" << endl;
}
/*
* ������FruitIn::unmake
* ������null
* ���ܣ�����ˮ��
*/
void FruitIn::unmake() {
	cout << "distroy fruit" << endl;
}
/*
* ������MeatIn::unmake
* ������null
* ���ܣ�������
*/
void MeatIn::unmake() {
	cout << "distroy meat" << endl;
}