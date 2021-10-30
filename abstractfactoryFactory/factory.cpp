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
		cout << "produce package factory" << endl;
		return new PackageFactory();
	}
	else if (fac == "kind" || fac == "Kind" || fac == "KIND") {
		cout << "produce kind factory" << endl;
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
		cout << "produce big jar factory" << endl;
		return new BigJar();
	}
	else if (a == "Little" || a == "little" || a == "LITTLE") {
		cout << "produce small jar factory" << endl;
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
		cout << "produce fruit factory" << endl;
		return new FruitIn();
	}
	else if (a == "Meat" || a == "meat" || a == "MEAT") {
		cout << "produce meat factory" << endl;
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
	cout << "produce a big jar" << endl;
}
/*
* ������LittleJar::make
* ������null
* ���ܣ�����һ��С��ͷ��
*/
void LittleJar::make() {
	cout << "produce a little jar" << endl;
}
/*
* ������FruitIn::make
* ������null
* ���ܣ�����ˮ��
*/
void FruitIn::make() {
	cout << "produce fruit" << endl;
}
/*
* ������MeatIn::make
* ������null
* ���ܣ�������
*/
void MeatIn::make() {
	cout << "produce meat" << endl;
}