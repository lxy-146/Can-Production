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
	cout << "┏┓       ┏┓┏┓   " << endl;
	cout << "┃┃┏━┳┳┳━┓┃┗┛┣━┳┳┓   " << endl;
	cout << "┃┗┫┃┃┃┃┻┫┗┓┏┫┃┃┃┃" << endl;
	cout << "┗━┻━┻━┻━┛ ┗┛┗━┻━┛                        please choose what to show : "<< endl;
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

//罐头生产
void produce() {
	//单例模式、观察者模式
	cout << endl;
	cout << "=====Take order:10 fruit,100 meat!=====" << endl;
	OrderSubject* ordersubject = new OrderSubject();//创建一个与observe有关的subject类用来对observe进行控制
	Observe* fruitobserve = new FruitObserve();//水果方面的observe，与subject进行连接
	Observe* meatobserve = new MeatObserve();//肉方面的observe，与subject进行连接
	ordersubject->Attach(fruitobserve);//将水果observe进行连接
	ordersubject->Attach(meatobserve);//将肉observe进行连接
	ordersubject->SetOrder(10, 100);//创建一个订单：购买10个水果，100个肉
	//ordersubject->SetOrder(100, 10);
	cout <<"=======================================\n" << endl;
	sleep();


	//抽象工厂模式、工厂模式、命令模式
	cout << "=====Produce package and contents!=====" << endl;
	FactoryProducer facproducer;//抽象工厂模式，用来生产工厂的类
	AbstractFactory* kindfactory = facproducer.getFactory("kind");//生产种类工厂
	AbstractFactory* packagefactory = facproducer.getFactory("package");//生产包装工厂
	Kind* kind = kindfactory->getKind("fruit");//工厂模式，生产水果类
	Package* package = packagefactory->getPackage("big");//生产大包装
	Broker broker;//命令模式，命令总控器
	broker.takeorder(new KMakeOrder(kind));//添加生产相关指令
	broker.takeorder(new PMakeOrder(package));//同上
	broker.placeorder();//执行所有命令
	broker.clear();//清除所有命令
	cout << "=======================================\n" << endl;
	sleep();


	//外观模式、解释器模式
	EquipmentBoot eb;
	eb.Boot();
	sleep();
	//装饰者模式
	cout << endl;
	cout << "=====Assemble cans!=====" << endl;
	Can* fruit_can = new FruitCan();//实例化一个蔬菜罐头
	Can* meat_can = new MeatCan();//实例化一个肉罐头
	Small_Can small_fruit_can = Small_Can(fruit_can);//生产小型蔬菜罐头
	Big_Can big_meat_can = Big_Can(meat_can);//生产大型肉罐头
	small_fruit_can.show();
	big_meat_can.show();
	cout << "=======================================\n" << endl;
	sleep();

	cout << "=====Produce more cans!=====" << endl;
	flyweight();
	cout << "=======================================\n" << endl;
	sleep();
	//惰性工厂模式，生产各种类型的罐头
	//双胞胎（twin）模式，生产组合类型罐头
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

	//原型模式包装罐头
	cout << "=====Pack cans!=====" << endl;
	auto* fruitCanPack = new packConcPrototype("big","fruit");
	fruitCanPack->display();
	//对构造的原型进行展示
	auto* cloneFruitCanPack = fruitCanPack->clone();
	cloneFruitCanPack->display();
	//拷贝一个原型罐头包装
	auto* resizedFruitCanPack = fruitCanPack->clone();
	resizedFruitCanPack->setSize("small");
	resizedFruitCanPack->display();
	//利用原型模式拷贝，改变大小后包装罐头
	auto* retypedFruitCanPack = fruitCanPack->clone();
	retypedFruitCanPack->setType("meat");
	retypedFruitCanPack->display();
	//CanStore::GetInstance()->ShowAll();
	cout << "=======================================\n" << endl;
	sleep();

	//空对象模式对订单操作
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
//享元+桥梁
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
//空对象
void nullobject()
{
	AbstractBuyer* b1 = BuyerFactory::getBuyer("WalMart");
	AbstractBuyer* b2 = BuyerFactory::getBuyer("Carrefour");
	AbstractBuyer* b3 = BuyerFactory::getBuyer("Hualian");
	AbstractBuyer* b4 = BuyerFactory::getBuyer("Darunfa");
	AbstractBuyer* b5 = BuyerFactory::getBuyer("Wumei");
	//创建采购商
	cout << "WalMart: " << b1->getName() << endl;
	cout << "Carrefour: " << b2->getName() << endl;
	cout << "Hualian: " << b3->getName() << endl;
	cout << "Darunfa: " << b4->getName() << endl;
	cout << "Wumei: " << b5->getName() << endl;
	//使用采购商对象中函数getName来确定是否在清单上
	delete b1; b1 = NULL;
	delete b2; b2 = NULL;
	delete b3; b3 = NULL;
	delete b4; b4 = NULL;
	delete b5; b5 = NULL;
	//安全删除所有指针
}

//订单购买
//中介者
void mediator() {//简单的中介者
	ConcreteMediator* p = new ConcreteMediator();
	Colleague* pCol1 = new ConcreteColleague_0(p);
	Colleague* pCol2 = new ConcreteColleague_1(p);
	p->addColleague(pCol1, pCol2);
	pCol1->send("老板您好，我需要买罐头");
	pCol2->send("您好，我这里有10个罐头可以卖给你");
	delete pCol1;
	delete pCol2;
	delete p;
}
//迭代器+状态+单例模式
void IteratorStateSingeton() {
	//创建迭代器和容器
	int id = 0;
	vector<Order2>* list = new vector<Order2>;//list是订单的容器的指针
	ConcreteAggregate* aggregate = new ConcreteAggregate(list);
	ConcreteIterator* iterator = new ConcreteIterator();
	aggregate->createIterator(iterator, id);
	//输入指令进行操作，可以添加订单也可以删除订单
	//每一天过去之后需要主动的更改订单的状态，
	//所以需要日期的辅助记时变量以及订单数目辅助变量
	int nowDay = 0;//当前日期
	int count = 0;//订单数目
	cout << "请输入指令:" << endl;
	cout << "输入0可以退出" << endl;
	cout << "输入1可以添加订单" << endl;
	cout << "输入2可以删除指定的订单" << endl;
	cout << "输入3可以顺序遍历查看订单" << endl;
	cout << "输入4可以倒序遍历查看订单" << endl;
	cout << "输入5可以查看当前的订单数目" << endl;
	cout << "输入6可以查看当前的订单" << endl;
	cout << "输入7可以查看当前订单的下一个" << endl;
	cout << "输入8可以查看当前订单的第一个" << endl;
	cout << "输入9可以查看当前订单的最后一个" << endl;
	cout << "输入10可以增加一天的日期" << endl;
	while (1) {
		cout << endl << "今天是第" << nowDay << "天" << endl;
		int command;
		cout << "请输入您的指令" << endl;
		cin >> command;
		cout << "您输入的指令为:" << command << endl;
		if (command == 0)
			break;
		//添加指令
		else if (command == 1)
		{
			//添加订单到容器
			aggregate->addOrder(count, nowDay);
			count++;//订单数增加
			//迭代器的参数更新,需要注意起始的订单id变化
			iterator->SetIterator(id, count);
		}
		else if (command == 2) {
			//删除已经完成的订单
			if (aggregate->deleteOrder())
			{
				cout << "删除成功" << endl;
				count--;//删除订单


				//迭代器的参数更新,需要注意起始的订单id变化
				iterator->SetIterator(id, count);
			}
			else
				cout << "输入的id错误,删除失败" << endl;
		}
		else if (command == 3) {
			//顺序遍历
			aggregate->showHtoT();
		}
		else if (command == 4)
		{	//逆序遍历
			aggregate->showTtoH();
		}
		else if (command == 5) {
			//获取当前的订单的数目
			cout << "当前的订单数目为:" << endl;
			cout << aggregate->getSize() << endl;
		}
		else if (command == 6) {
			//查看当前的订单
			(iterator->now(aggregate).ShowState());
		}
		else if (command == 7) {
			//查看当前订单的下一个
			iterator->next(aggregate).ShowState();
		}
		else if (command == 8) {
			//查看当前订单的第一个
			iterator->first(aggregate).ShowState();
		}
		else if (command == 9) {
			//查看当前订单的最后一个
			iterator->end(aggregate).ShowState();
		}
		else if (command == 10) {
			nowDay++;//日期增加,需要指令输入实现
		//订单信息需要根据时间变化更新
			aggregate->InfoUpgrate(nowDay);
		}
		else
			cout << "输入指令错误，请重新输入" << endl;
	}
	delete list;
}
//建造者
void builder() {
	int a;
	group_builder* builder = new group_builder();
	while (1) {
		builder->show_all_group();
		builder->create_group();
		cout << "输入0以结束此功能" << endl;
		cout << "输入1以继续添加套餐" << endl;
		cin >> a;
		if (a == 0)
			break;
		else if (a == 1)
			;
		else
		{
			cout << "输入的指令错误请重新输入" << endl;
			system("pause");
		}

	}
	delete builder;
}
//jpch模式展示部分
void order() {
	while (1) {
		cout << "请输入指令操作" << endl;
		cout << "输入1展示建造者模式、组件模式、策略模式组合" << endl;
		cout << "输入2展示中介者模式" << endl;
		cout << "输入3展示状态模式、迭代器模式、单例模式组合" << endl;
		cout << "输入4退出" << endl;
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
		else cout << "您输入的指令错误" << endl;
	}
}

//人员管理
void personnelmanagement() {

	//构建责任链
	Handler* leader = new Leader;
	Handler* manager = new Manager;
	Handler* boss = new Boss;

	leader->setNextHandler(manager);
	manager->setNextHandler(boss);
	boss->setNextHandler(nullptr);

	//创建请求
	Request* request1 = new Request(1, "请短假");
	Request* request2 = new Request(4, "请长假");
	Request* request3 = new Request(3, "申请加薪");
	Request* request4 = new Request(6, "申请升职");
	Request* request5 = new Request(7, "离职");
	cout << "0.退出" << endl;
	//处理请求
	cout << "请选择请求类型: ";
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
			cout << "不存在该类请求！" << endl;
		}
		cout << "请选择请求类型：";
	}

}

//财务管理
void finance() {
	Originator* org = new Originator(150000);
	Caretaker* crt = new Caretaker();
	crt->addMemento(org->createMemento());
	org->setState("2021.11.4");                   //更新账本状态为2021.11.4
	org->printInfo();

	crt->addMemento(org->createMemento());
	org->setState("2021.11.5");
	org->printInfo();

	crt->addMemento(org->createMemento());
	org->setState("2021.11.6");
	org->printInfo();

	org->restoreMemento(crt->getMemento());        //恢复至上一条记录
	org->restoreMemento(crt->getMemento());        //再恢复一次

	org->setFund(1, 50000);                        //资金+50000
	org->printInfo();                              //显示当前账本状态信息和资金总数

	Accountant* acc = new Accountant(org);
	acc->printInfo();
	int t;
	while (true) {
		cout << "请输入0以退出:";
		cin >> t;
		if (t == 0)break;
	}
}

//设备管理
void statevisitor() {
	State2* list[] = { new IdleState(),new RunningState(),new DamageState() };
	StateVisitor rv;
	Context* c = new Context();
	for (int i = 0; i < 3; i++)
	{
		/*
			不同的State调用自己的accept方法，参数为StateVisitor，对State进行访问，获取当前设备的状态
			然后由context调用request方法，对当前状态进行处理
		*/
		list[i]->accept(rv);
		c->request();
	}
	int r;
	while (true) {
		cout << "请输入0以退出：";
		cin >> r;
		if (r == 0)break;
	}
}





