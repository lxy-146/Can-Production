#include"flyweight2.h"
/*
*函数：MiddleCan::make
*参数：null
*功能：生产中等型号罐头
*/
void MiddleCan::make() {
	kind->make();
	cout << "middle can" << endl;
}
/*
*函数：FishKind::make
*参数：null
*功能：生产鱼罐头
*/
void FishKind::make() {
	cout << "produce fish ";
}
/*
*函数：PorkKind::make
*参数：null
*功能：生产猪肉罐头
*/
void PorkKind::make() {
	cout << "produce pork ";
}
/*
*函数：BeefKind::make
*参数：null
*功能：生产牛肉罐头
*/
void BeefKind::make() {
	cout << "produce beef ";
}
/*
*函数：BeefKind::unmake
*参数：null
*功能：撤销牛肉罐头
*/
void BeefKind::unmake() {
	cout << "destory beefcan" << endl;
}
/*
*函数：PorkKind::unmake
*参数：null
*功能：撤销猪肉罐头
*/
void PorkKind::unmake() {
	cout << "destory porkcan" << endl;
}
/*
*函数：FishKind::unmake
*参数：null
*功能：撤销鱼罐头
*/
void FishKind::unmake() {
	cout << "destory fishcan" << endl;
}
/*
*函数：MiddleCan::unmake
*参数：null
*功能：撤销中型罐头
*/
void MiddleCan::unmake() {
	cout << "destroy middlecan" << endl;
}
/*
*函数：Factory
*参数：string key
*功能：如果没有需要的类型的罐头，则通过需求生产对应的罐头；如果已经有此类罐头，则返回此类罐头Can
*/
Can* Factory::GetFlyweights(string key) {
	if (flyweights.count(key) == 0)
	{
		cout << "Factory:GetFlyweights:将新的类型加入到工厂中" << endl;
		Can_pack* c;
		if (key == "bigfruit") c = new Big_Can(new FruitCan());
		else if (key == "smallfruit") c = new Small_Can(new FruitCan());
		else if (key == "bigmeat")c = new Big_Can(new MeatCan());
		else if (key == "smallmeat")c = new Small_Can(new MeatCan());
		flyweights.insert(make_pair(key, c));
	}
	else
		cout << "Factory:GetFlyweights:该类型已存在，使用已有类型" << endl;
	return (Can*)flyweights[key];
}



