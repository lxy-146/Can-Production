#include"header.h"
#include"storehouse.h"
#include"canfactory.h"
#include"stapleobserve.h"
#include"prototype.h"
#include"factory.h"
#include"command.h"
#include"decoration.h"
#include"can.h"
#include"Finance.h"
#include "ChainOfResponsibility.h"
#include "MediatorModel.h"
#include"OrderStateMode.h"
#include"IteratorMode .h"
#include"canclass.h"
#include"grouping_packaging.h"
#include"kindof.h"
#include"State.h"
#include"EquipmentBoot.h"
#include"Context.h"
#include"flyweight2.h"
#include"NullObject.h"

void finance();
void produce();
void personnelmanagement();
void mediator();
void IteratorStateSingeton();
void jpch();
void order();
void statevisitor();
void flyweight();
void nullobject();

void showhome() {
	system("cls");
	cout << "==========================================================================" << endl;
	cout << "����       ��������   " << endl;
	cout << "���������ששש����������ǩ��שש�   " << endl;
	cout << "�����ϩ��������ߩϩ������ϩ�������" << endl;
	cout << "�����ߩ��ߩ��ߩ��� ���������ߩ���                        please choose what to show : "<< endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "      ******       ******" << endl;
	cout << "    **********   **********" << endl;
	cout << "  ************* *************" << endl;
	cout << " *****************************              1.can-produce  "<< endl;
	cout << " *****************************              2.order management             " << endl;
	cout << " *****************************              3.finance management "<< endl;
	cout << "  ***************************               4.person management" << endl;
	cout << "    ***********************                 5.equipment management" << endl;
	cout << "      *******************                   0.exit" << endl;
	cout << "        ***************" << endl;
	cout << "          ***********" << endl;
	cout << "            *******" << endl;
	cout << "              ***" << endl;
	cout << "               *" << endl;
	cout << "==========================================================================" << endl;
	/*
	cout << "==============================================="<< endl;
	cout << "                                              " << endl;
	cout << " please choose what to show:                  " << endl;
	cout << "                                              " << endl;
	cout << "                       1.can-produce          " << endl;
	cout << "                       2.order management     " << endl;
	cout << "                       3.finance management   " << endl;
	cout << "                       4.person management    " << endl;
	cout << "                       5.equipment management " << endl;
	cout << "                       0.exit                 " << endl;
	cout << "                                              " << endl;
	cout << "                                              " << endl;
	cout << "===============================================" << endl;*/
}

int main() {
	int i=-1;
	while (true) {
		showhome();
		cout << "please choose what to show:";
		cin >> i;
		if (i == 1)
			produce();
		else if (i == 2)
			order();
		else if (i == 3)
			finance();
		else if (i == 4)
			personnelmanagement();
		else if (i == 5)
			statevisitor();
		else if (i == 0)
			break;
		else
			cout << "u input wrong thing" << endl;
	}
	return 0;
}
void sleep() {
	Sleep(2000);
}

//��ͷ����
void produce() {
	//����ģʽ���۲���ģʽ
	cout << endl;
	cout << "=====Take order:10 fruit,100 meat!=====" << endl;
	OrderSubject* ordersubject = new OrderSubject();//����һ����observe�йص�subject��������observe���п���
	Observe* fruitobserve = new FruitObserve();//ˮ�������observe����subject��������
	Observe* meatobserve = new MeatObserve();//�ⷽ���observe����subject��������
	ordersubject->Attach(fruitobserve);//��ˮ��observe��������
	ordersubject->Attach(meatobserve);//����observe��������
	ordersubject->SetOrder(10, 100);//����һ������������10��ˮ����100����
	//ordersubject->SetOrder(100, 10);
	cout <<"=======================================\n" << endl;
	sleep();


	//���󹤳�ģʽ������ģʽ������ģʽ
	cout << "=====Produce package and contents!=====" << endl;
	FactoryProducer facproducer;//���󹤳�ģʽ������������������
	AbstractFactory* kindfactory = facproducer.getFactory("kind");//�������๤��
	AbstractFactory* packagefactory = facproducer.getFactory("package");//������װ����
	Kind* kind = kindfactory->getKind("fruit");//����ģʽ������ˮ����
	Package* package = packagefactory->getPackage("big");//�������װ
	Broker broker;//����ģʽ�������ܿ���
	broker.takeorder(new KMakeOrder(kind));//����������ָ��
	broker.takeorder(new PMakeOrder(package));//ͬ��
	broker.placeorder();//ִ����������
	broker.clear();//�����������
	cout << "=======================================\n" << endl;
	sleep();


	//���ģʽ��������ģʽ
	EquipmentBoot eb;
	eb.Boot();
	sleep();
	//װ����ģʽ
	cout << endl;
	cout << "=====Assemble cans!=====" << endl;
	Can* fruit_can = new FruitCan();//ʵ����һ���߲˹�ͷ
	Can* meat_can = new MeatCan();//ʵ����һ�����ͷ
	Small_Can small_fruit_can = Small_Can(fruit_can);//����С���߲˹�ͷ
	Big_Can big_meat_can = Big_Can(meat_can);//�����������ͷ
	small_fruit_can.show();
	big_meat_can.show();
	cout << "=======================================\n" << endl;
	sleep();

	cout << "=====Produce more cans!=====" << endl;
	flyweight();
	cout << "=======================================\n" << endl;
	sleep();
	//���Թ���ģʽ�������������͵Ĺ�ͷ
	//˫��̥��twin��ģʽ������������͹�ͷ
	cout << "=====Produce combined cans!=====" << endl;
	KindOfMeatCan::getMeatCan("Pork");
	KindOfMeatCan* beefcan = KindOfMeatCan::getMeatCan("beef");
	KindOfMeatCan* chicken = KindOfMeatCan::getMeatCan("chicken");
	KindOfMeatCan::printCurrentTypes();
	beefcan->show();
	chicken->show();
	cout << endl;

	KindOfFruitCan::getFruitCan("apple");
	KindOfFruitCan::getFruitCan("pear");
	KindOfFruitCan::getFruitCan("banana");
	KindOfFruitCan::printCurrentTypes();

	KindOfVegCan* bamboo_beef = KindOfVegCan::getVegCan("bamboo shoots", beefcan);
	KindOfVegCan* carrot_chicken = KindOfVegCan::getVegCan("carrot", chicken);
	KindOfVegCan* cucumber = KindOfVegCan::getVegCan("cucumber", NULL);
	KindOfVegCan::printCurrentTypes();
	bamboo_beef->mixed();
	carrot_chicken->mixed();
	cucumber->mixed();
	cout << "=======================================\n" << endl;
	sleep();

	//ԭ��ģʽ��װ��ͷ
	cout << "=====Pack cans!=====" << endl;
	auto* fruitCanPack = new packConcPrototype("big","fruit");
	fruitCanPack->display();
	//�Թ����ԭ�ͽ���չʾ
	auto* cloneFruitCanPack = fruitCanPack->clone();
	cloneFruitCanPack->display();
	//����һ��ԭ�͹�ͷ��װ
	auto* resizedFruitCanPack = fruitCanPack->clone();
	resizedFruitCanPack->setSize("small");
	resizedFruitCanPack->display();
	//����ԭ��ģʽ�������ı��С���װ��ͷ
	auto* retypedFruitCanPack = fruitCanPack->clone();
	retypedFruitCanPack->setType("meat");
	retypedFruitCanPack->display();
	//CanStore::GetInstance()->ShowAll();
	cout << "=======================================\n" << endl;
	sleep();

	//�ն���ģʽ�Զ�������
	cout <<"=====Finding Buyer=====" << endl;
	nullobject();
	cout << "=======================================\n" << endl;
	sleep();
	int i=-1;
	while (true) {
		cout << "input 0 to exit:" << endl;
		cin >> i;
		if (i == 0)break;
	}
}
//��Ԫ+����
void flyweight() {
	Kind* beefkind = new BeefKind();
	Kind* porkkind = new PorkKind();
	Kind* fishkind = new FishKind();
	MiddleCan* middlecan = new MiddleCan(beefkind);
	middlecan->make();
	Factory* factory = new Factory();

	int j=0;
	for (int i = 0; i < 6; i++) {
		Can* f;
		j = i % 4;
		switch (j) {
		case 0:
			f = factory->GetFlyweights("bigfruit");
			//f->show();
			break;
		case 1:
			f = factory->GetFlyweights("smallfruit");
			//f->show();
			break;
		case 2:
			f = factory->GetFlyweights("bigmeat");
			//f->show();
			break;
		case 3:
			f = factory->GetFlyweights("smallmeat");
			//f->show();
			break;
		}


	}
}
//�ն���
void nullobject()
{
	AbstractBuyer* b1 = BuyerFactory::getBuyer("WalMart");
	AbstractBuyer* b2 = BuyerFactory::getBuyer("Carrefour");
	AbstractBuyer* b3 = BuyerFactory::getBuyer("Hualian");
	AbstractBuyer* b4 = BuyerFactory::getBuyer("Darunfa");
	AbstractBuyer* b5 = BuyerFactory::getBuyer("Wumei");
	//�����ɹ���
	cout << "WalMart: " << b1->getName() << endl;
	cout << "Carrefour: " << b2->getName() << endl;
	cout << "Hualian: " << b3->getName() << endl;
	cout << "Darunfa: " << b4->getName() << endl;
	cout << "Wumei: " << b5->getName() << endl;
	//ʹ�òɹ��̶����к���getName��ȷ���Ƿ����嵥��
	delete b1; b1 = NULL;
	delete b2; b2 = NULL;
	delete b3; b3 = NULL;
	delete b4; b4 = NULL;
	delete b5; b5 = NULL;
	//��ȫɾ������ָ��
}

//��������
//�н���
void mediator() {//�򵥵��н���
	ConcreteMediator* p = new ConcreteMediator();
	Colleague* pCol1 = new ConcreteColleague_0(p);
	Colleague* pCol2 = new ConcreteColleague_1(p);
	p->addColleague(pCol1, pCol2);
	pCol1->send("�ϰ����ã�����Ҫ���ͷ");
	pCol2->send("���ã���������10����ͷ����������");
	delete pCol1;
	delete pCol2;
	delete p;
}
//������+״̬+����ģʽ
void IteratorStateSingeton() {
	//����������������
	int id = 0;
	vector<Order2>* list = new vector<Order2>;//list�Ƕ�����������ָ��
	ConcreteAggregate* aggregate = new ConcreteAggregate(list);
	ConcreteIterator* iterator = new ConcreteIterator();
	aggregate->createIterator(iterator, id);
	//����ָ����в�����������Ӷ���Ҳ����ɾ������
	//ÿһ���ȥ֮����Ҫ�����ĸ��Ķ�����״̬��
	//������Ҫ���ڵĸ�����ʱ�����Լ�������Ŀ��������
	int nowDay = 0;//��ǰ����
	int count = 0;//������Ŀ
	cout << "������ָ��:" << endl;
	cout << "����0�����˳�" << endl;
	cout << "����1������Ӷ���" << endl;
	cout << "����2����ɾ��ָ���Ķ���" << endl;
	cout << "����3����˳������鿴����" << endl;
	cout << "����4���Ե�������鿴����" << endl;
	cout << "����5���Բ鿴��ǰ�Ķ�����Ŀ" << endl;
	cout << "����6���Բ鿴��ǰ�Ķ���" << endl;
	cout << "����7���Բ鿴��ǰ��������һ��" << endl;
	cout << "����8���Բ鿴��ǰ�����ĵ�һ��" << endl;
	cout << "����9���Բ鿴��ǰ���������һ��" << endl;
	cout << "����10��������һ�������" << endl;
	while (1) {
		cout << endl << "�����ǵ�" << nowDay << "��" << endl;
		int command;
		cout << "����������ָ��" << endl;
		cin >> command;
		cout << "�������ָ��Ϊ:" << command << endl;
		if (command == 0)
			break;
		//���ָ��
		else if (command == 1)
		{
			//��Ӷ���������
			aggregate->addOrder(count, nowDay);
			count++;//����������
			//�������Ĳ�������,��Ҫע����ʼ�Ķ���id�仯
			iterator->SetIterator(id, count);
		}
		else if (command == 2) {
			//ɾ���Ѿ���ɵĶ���
			if (aggregate->deleteOrder())
			{
				cout << "ɾ���ɹ�" << endl;
				count--;//ɾ������


				//�������Ĳ�������,��Ҫע����ʼ�Ķ���id�仯
				iterator->SetIterator(id, count);
			}
			else
				cout << "�����id����,ɾ��ʧ��" << endl;
		}
		else if (command == 3) {
			//˳�����
			aggregate->showHtoT();
		}
		else if (command == 4)
		{	//�������
			aggregate->showTtoH();
		}
		else if (command == 5) {
			//��ȡ��ǰ�Ķ�������Ŀ
			cout << "��ǰ�Ķ�����ĿΪ:" << endl;
			cout << aggregate->getSize() << endl;
		}
		else if (command == 6) {
			//�鿴��ǰ�Ķ���
			(iterator->now(aggregate).ShowState());
		}
		else if (command == 7) {
			//�鿴��ǰ��������һ��
			iterator->next(aggregate).ShowState();
		}
		else if (command == 8) {
			//�鿴��ǰ�����ĵ�һ��
			iterator->first(aggregate).ShowState();
		}
		else if (command == 9) {
			//�鿴��ǰ���������һ��
			iterator->end(aggregate).ShowState();
		}
		else if (command == 10) {
			nowDay++;//��������,��Ҫָ������ʵ��
		//������Ϣ��Ҫ����ʱ��仯����
			aggregate->InfoUpgrate(nowDay);
		}
		else
			cout << "����ָ���������������" << endl;
	}
	delete list;
}
//������
void builder() {
	int a;
	group_builder* builder = new group_builder();
	while (1) {
		builder->show_all_group();
		builder->create_group();
		cout << "����0�Խ����˹���" << endl;
		cout << "����1�Լ�������ײ�" << endl;
		cin >> a;
		if (a == 0)
			break;
		else if (a == 1)
			;
		else
		{
			cout << "�����ָ���������������" << endl;
			system("pause");
		}

	}
	delete builder;
}
//jpchģʽչʾ����
void order() {
	while (1) {
		cout << "������ָ�����" << endl;
		cout << "����1չʾ������ģʽ�����ģʽ������ģʽ���" << endl;
		cout << "����2չʾ�н���ģʽ" << endl;
		cout << "����3չʾ״̬ģʽ��������ģʽ������ģʽ���" << endl;
		cout << "����4�˳�" << endl;
		int order;
		cin >> order;
		if (order == 1) {
			builder();
		}
		else if (order == 2) {
			mediator();
		}
		else if (order == 3) {
			IteratorStateSingeton();
		}
		else if (order == 4) {
			break;
		}
		else cout << "�������ָ�����" << endl;
	}
}

//��Ա����
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

//�������
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
	int t;
	while (true) {
		cout << "������0���˳�:";
		cin >> t;
		if (t == 0)break;
	}
}

//�豸����
void statevisitor() {
	State2* list[] = { new IdleState(),new RunningState(),new DamageState() };
	StateVisitor rv;
	Context* c = new Context();
	for (int i = 0; i < 3; i++)
	{
		/*
			��ͬ��State�����Լ���accept����������ΪStateVisitor����State���з��ʣ���ȡ��ǰ�豸��״̬
			Ȼ����context����request�������Ե�ǰ״̬���д���
		*/
		list[i]->accept(rv);
		c->request();
	}
	int r;
	while (true) {
		cout << "������0���˳���";
		cin >> r;
		if (r == 0)break;
	}
}





