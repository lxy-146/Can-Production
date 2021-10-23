#include"header.h"
#include"storehouse.h"
#include"canfactory.h"
#include"stapleobserve.h"
#include"prototype.h"
#include"decoration.h"
#include"factory.h"
#include"command.h"

int main() {
	OrderSubject* ordersubject=new OrderSubject();//����һ����observe�йص�subject��������observe���п���
	Observe* fruitobserve = new FruitObserve();//ˮ�������observe����subject��������
	Observe* meatobserve = new MeatObserve();//�ⷽ���observe����subject��������
	ordersubject->Attach(fruitobserve);//��ˮ��observe��������
	ordersubject->Attach(meatobserve);//����observe��������
	ordersubject->SetOrder(10, 100);//����һ������
	ordersubject->SetOrder(100, 10);

	FactoryProducer facproducer;//���󹤳�ģʽ������������������
	AbstractFactory* kindfactory = facproducer.getFactory("kind");//�������๤��
	AbstractFactory* packedgefactory = facproducer.getFactory("packedge");//������װ����
	Kind* kind = kindfactory->getKind("fruit");//����ģʽ������ˮ����
	Packedge* packedge = packedgefactory->getPackedge("big");//�������װ
	Broker broker;//����ģʽ�������ܿ���
	broker.takeorder(new KMakeOrder(kind));//����������ָ��
	broker.takeorder(new PMakeOrder(packedge));//ͬ��
	broker.placeorder();//ִ����������
	broker.clear();//�����������
	kind = kindfactory->getKind("meat");//����Ϊ�ظ�
	packedge = packedgefactory->getPackedge("little");
	broker.takeorder(new KMakeOrder(kind));
	broker.takeorder(new PMakeOrder(packedge));
	broker.placeorder();

	Can* veg_can = new Veg_Can();//ʵ����һ���߲˹�ͷ
	Can* meat_can = new Meat_Can();//ʵ����һ�����ͷ

	Small_Can small_veg_can = Small_Can(veg_can);//����С���߲˹�ͷ
	Big_Can big_veg_can = Big_Can(veg_can);//���������߲˹�ͷ
	small_veg_can.show();
	big_veg_can.show();

	Small_Can small_meat_can = Small_Can(meat_can);//����С���߲˹�ͷ
	Big_Can big_meat_can = Big_Can(meat_can);//���������߲˹�ͷ
	small_meat_can.show();
	big_meat_can.show();

	//ԭ��ģʽ��װ��ͷ
	ConcretePrototype* fruitCanPrototype = new ConcretePrototype("Fruit can is already packed.");
	fruitCanPrototype->show();
	ConcretePrototype2* fruitCan1 = (ConcretePrototype2*)fruitCanPrototype->clone();
	fruitCan1->show();
	ConcretePrototype2* fruitCan2 = (ConcretePrototype2*)fruitCanPrototype->clone();
	fruitCan2->show();

	return 0;
}