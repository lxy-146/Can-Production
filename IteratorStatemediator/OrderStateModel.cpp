/*
* OrderStateMode.h - Definition
*/

#include"OrderStateMode.h"
#include"storehouse.h"

/*
   函数：Order2::SumDays
   参数：null
   功能：计算订单执行所需要的时间,每个罐头的数量获取通过罐头仓库单例实体的函数得到
*/
int Order2::SumDays() {
	cout << "classname:" << "Order2" << "method name:" << "SumDays" << "action description:" << "计算订单执行所需要的时间,每个罐头的数量获取通过罐头仓库单例实体的函数得到" << endl;
	int number = 4;//所需要的罐头的种类数目
	int* can = new int[number];
	int* cost = new int[number];
	int* store = new int[number];
	cout << "各种罐头的数量(大水果、小水果、大肉、小肉):" << endl;
	for (int i = 0; i < number; i++)
	{
		  can[i]=1;
	}
	//每种罐头的生产周期
	//lf\sf\lm\sm
	cost[0] = 6; cost[1] = 4;
	cost[2] = 9; cost[3] = 6;
	CanStore* sto =CanStore::GetInstance();
	store[0] = sto->GetLargeFruitCan();
	store[1] = sto->GetSmallFruitCan();
	store[2] = sto->GetLargeMeatCan();
	store[3] = sto->GetSmallMeatCan();
	//计算得到每种罐头所需要的时间最大值就是订单的生产周期
	int temp;
	if (store[0] >= can[0])//存储的罐头数量比需要的多
		temp = 0;
	else
		temp = cost[0] * (can[0] - store[0]);
	//temp>=0确保之后的时间不可能小于0
	for (int i = 1; i < number; i++)
		if (temp < cost[i] * (can[i] - store[i]))//出现了需要时间更多的罐头种类
			temp = cost[i] * (can[i] - store[i]);
	for (int i = 0; i < number; i++)
		cout << can[i] << " " ;
	cout << endl;
	cout << "订单完成所需时间为:" << endl;
	cout << temp << endl;
	delete[]can;
	delete[]cost;
	delete[]store;
	this->day = temp;
	return this->day;
}

/*
   函数：Order2::ShowState
   参数：null
   功能：输出当前的状态信息
*/
void Order2::ShowState() {
	
	if (this->state->stateNum == 0)
		cout << "第" << this->GetCurrentay() << "天：订单已经创建" << endl;

	else if (this->state->stateNum == 1)
		cout << "第" << this->GetCurrentay() << "天：订单还在制作" << endl;
		
	else
		cout << "第" << this->GetCurrentay() <<  "天订单已经完成" << endl;
}

