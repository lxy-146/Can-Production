#include"header.h"
#include"storehouse.h"
#include"canfactory.h"
#include"stapleobserve.h"
#include"prototype.h"
#include"decoration.h"
#include"factory.h"
#include"command.h"
#include"can.h"
#include"Finance.h"
#include "ChainOfResponsibility.h"

void finance();
void produce();
void personnelmanagement();

int main() {
	

	produce();
	finance();
	personnelmanagement();

	return 0;
}

void produce() {
	OrderSubject* ordersubject = new OrderSubject();//����һ����observe�йص�subject��������observe���п���
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

	//װ����ģʽ
	Can* fruit_can = new FruitCan();//ʵ����һ���߲˹�ͷ
	Can* meat_can = new MeatCan();//ʵ����һ�����ͷ

	Small_Can small_fruit_can = Small_Can(fruit_can);//����С���߲˹�ͷ
	Big_Can big_fruit_can = Big_Can(fruit_can);//���������߲˹�ͷ
	small_fruit_can.show();
	big_fruit_can.show();

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
}

void finance() {
	Originator* org = new Originator(150000);
	Caretaker* crt = new Caretaker();
	crt->addMemento(org->createMemento());
	org->setState("2021.11.4");                   //�����˱�״̬Ϊ2021.11.4
	org->printInfo();

	crt->addMemento(org->createMemento());
	org->setState("2021.11.5");
	org->printInfo();

	crt->addMemento(org->createMemento());
	org->setState("2021.11.6");
	org->printInfo();

	org->restoreMemento(crt->getMemento());        //�ָ�����һ����¼
	org->restoreMemento(crt->getMemento());        //�ٻָ�һ��

	org->setFund(1, 50000);                        //�ʽ�+50000
	org->printInfo();                              //��ʾ��ǰ�˱�״̬��Ϣ���ʽ�����

	Accountant* acc = new Accountant(org);
	acc->printInfo();

}



void personnelmanagement() {

	//����������
	Handler* leader = new Leader;
	Handler* manager = new Manager;
	Handler* boss = new Boss;

	leader->setNextHandler(manager);
	manager->setNextHandler(boss);
	boss->setNextHandler(nullptr);

	//��������
	Request* request1 = new Request(1, "��̼�");
	Request* request2 = new Request(4, "�볤��");
	Request* request3 = new Request(3, "�����н");
	Request* request4 = new Request(6, "������ְ");
	Request* request5 = new Request(7, "��ְ");
	cout << "0.�˳�" << endl;
	//��������
	cout << "��ѡ����������: ";
	int num = 1;
	while (cin >> num) {
		if (num == 0) {
			break;
		}
		else if (num > 0 && num < 6) {
			switch (num) {
			case 1: leader->handleRequest(request1->getLevel()); break;
			case 2: leader->handleRequest(request2->getLevel()); break;
			case 3: leader->handleRequest(request3->getLevel()); break;
			case 4: leader->handleRequest(request4->getLevel()); break;
			case 5: leader->handleRequest(request5->getLevel()); break;
			}
		}
		else {
			cout << "�����ڸ�������" << endl;
		}
		cout << "��ѡ���������ͣ�";
	}

}