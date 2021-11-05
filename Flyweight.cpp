#include"flyweight2.h"

/*
*������MiddleCan::make
*������null
*���ܣ������е��ͺŹ�ͷ
*/
void MiddleCan::make() {
	cout << "MiddleCan:make:����ģʽ�������ͣ�ˮ�������ࣩ��ͷ" << endl;
	kind->make();
	cout << "middle can" << endl;
}
/*
*������FishKind::make
*������null
*���ܣ��������ͷ
*/
void FishKind::make() {
	cout << "produce fish" << endl;
}
/*
*������PorkKind::make
*������null
*���ܣ����������ͷ
*/
void PorkKind::make() {
	cout << "produce pork" << endl;
}
/*
*������BeefKind::make
*������null
*���ܣ�����ţ���ͷ
*/
void BeefKind::make() {
	cout << "produce beef" << endl;
}
/*
*������BeefKind::unmake
*������null
*���ܣ�����ţ���ͷ
*/
void BeefKind::unmake() {
	cout << "destory beefcan" << endl;
}
/*
*������PorkKind::unmake
*������null
*���ܣ����������ͷ
*/
void PorkKind::unmake() {
	cout << "destory porkcan" << endl;
}
/*
*������FishKind::unmake
*������null
*���ܣ��������ͷ
*/
void FishKind::unmake() {
	cout << "destroy fishcan" << endl;
}
/*
*������MiddleCan::unmake
*������null
*���ܣ��������͹�ͷ
*/
void MiddleCan::unmake() {
	cout << "destroy middlecan" << endl;
}
/*
*������Factory
*������string key
*���ܣ����û����Ҫ�����͵Ĺ�ͷ����ͨ������������Ӧ�Ĺ�ͷ������Ѿ��д����ͷ���򷵻ش����ͷCan
*/
Can* Factory::GetFlyweights(string key) {
	if (flyweights.count(key) == 0) {
		cout << "Factory:GetFlyweight:���µ����ͼ��뵽������" << endl;
		Can_pack* c;
		if (key == "bigfruit")c = new Big_Can(new FruitCan());
		else if (key == "smallfruit")c = new Small_Can(new FruitCan());
		else if (key == "bigmeat")c = new Big_Can(new MeatCan());
		else if (key == "smallmeat")c = new Small_Can(new MeatCan());
		flyweights.insert(make_pair(key, c));
	}
	else
		cout << "Factory:GetFlyweights:�������Ѵ��ڣ�ʹ����������" << endl;
	return (Can*)flyweights[key];
}