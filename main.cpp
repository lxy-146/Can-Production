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
	OrderSubject* ordersubject = new OrderSubject();//创建一个与observe有关的subject类用来对observe进行控制
	Observe* fruitobserve = new FruitObserve();//水果方面的observe，与subject进行连接
	Observe* meatobserve = new MeatObserve();//肉方面的observe，与subject进行连接
	ordersubject->Attach(fruitobserve);//将水果observe进行连接
	ordersubject->Attach(meatobserve);//将肉observe进行连接
	ordersubject->SetOrder(10, 100);//创建一个订单
	ordersubject->SetOrder(100, 10);

	FactoryProducer facproducer;//抽象工厂模式，用来生产工厂的类
	AbstractFactory* kindfactory = facproducer.getFactory("kind");//生产种类工厂
	AbstractFactory* packedgefactory = facproducer.getFactory("packedge");//生产包装工厂
	Kind* kind = kindfactory->getKind("fruit");//工厂模式，生产水果类
	Packedge* packedge = packedgefactory->getPackedge("big");//生产大包装
	Broker broker;//命令模式，命令总控器
	broker.takeorder(new KMakeOrder(kind));//添加生产相关指令
	broker.takeorder(new PMakeOrder(packedge));//同上
	broker.placeorder();//执行所有命令
	broker.clear();//清除所有命令
	kind = kindfactory->getKind("meat");//以下为重复
	packedge = packedgefactory->getPackedge("little");
	broker.takeorder(new KMakeOrder(kind));
	broker.takeorder(new PMakeOrder(packedge));
	broker.placeorder();

	//装饰者模式
	Can* fruit_can = new FruitCan();//实例化一个蔬菜罐头
	Can* meat_can = new MeatCan();//实例化一个肉罐头

	Small_Can small_fruit_can = Small_Can(fruit_can);//生产小型蔬菜罐头
	Big_Can big_fruit_can = Big_Can(fruit_can);//生产大型蔬菜罐头
	small_fruit_can.show();
	big_fruit_can.show();

	Small_Can small_meat_can = Small_Can(meat_can);//生产小型蔬菜罐头
	Big_Can big_meat_can = Big_Can(meat_can);//生产大型蔬菜罐头
	small_meat_can.show();
	big_meat_can.show();

	//原型模式包装罐头
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

}



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