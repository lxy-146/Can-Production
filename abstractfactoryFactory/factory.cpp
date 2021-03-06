/*
* factory.h-defination
*/

#include"header.h"
#include"factory.h"


/*
* 函数： FactoryProducer::getFactory
* 参数： string fac
* 功能：通过fac的内容返回对应功能的工厂
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
* 函数： PackageFactory::getPackage
* 参数： string a
* 功能： 通过a的内容返回对应的包装类
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
* 函数：PackageFactory::getKind
* 参数：string a
* 功能：当用户错误调用时返回对应提示
*/
Kind* PackageFactory::getKind(string a) {
	cout << "i can't do this" << endl;
	return nullptr;
}
/*
* 函数：KindFactory::getKind
* 参数：string a
* 功能：根据a返回对应正确的种类类，如果a是水果，就返回FruitIn，是肉就返回Meat
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
* 函数：KindFactory::getPackage
* 参数：string a
* 功能：当用户错误调用时返回对应提示
*/
Package* KindFactory::getPackage(string a) {
	cout << "i can't do this" << endl;
	return nullptr;
}
/*
* 函数：BigJar::make
* 参数：null
* 功能：生产一个大罐头壳
*/
void BigJar::make() {
	cout << "BigJar:make:produce a big jar" << endl;
}
/*
* 函数：LittleJar::make
* 参数：null
* 功能：生产一个小罐头壳
*/
void LittleJar::make() {
	cout << "LittleJar:make:produce a little jar" << endl;
}
/*
* 函数：FruitIn::make
* 参数：null
* 功能：生产水果
*/
void FruitIn::make() {
	cout << "FruitIn:make:produce fruit" << endl;
}
/*
* 函数：MeatIn::make
* 参数：null
* 功能：生产肉
*/
void MeatIn::make() {
	cout << "MeatIn:make:produce meat" << endl;
}
/*
* 函数：BigJar::unmake
* 参数：null
* 功能：销毁一个大罐头壳
*/
void BigJar::unmake() {
	cout << "distroy a big jar" << endl;
}
/*
* 函数：LittleJar::unmake
* 参数：null
* 功能：销毁一个小罐头壳
*/
void LittleJar::unmake() {
	cout << "distroy a little jar" << endl;
}
/*
* 函数：FruitIn::unmake
* 参数：null
* 功能：销毁水果
*/
void FruitIn::unmake() {
	cout << "distroy fruit" << endl;
}
/*
* 函数：MeatIn::unmake
* 参数：null
* 功能：销毁肉
*/
void MeatIn::unmake() {
	cout << "distroy meat" << endl;
}