#include"OrderStateMode.h"

//���㶩��ִ������Ҫ��ʱ��
//ÿ����ͷ��������ȡͨ����ͷ�ֿⵥ��ʵ��ĺ����õ�
int Order2::SumDays() {
	int number = 4;//����Ҫ�Ĺ�ͷ��������Ŀ
	int* can = new int[number];
	int* cost = new int[number];
	int* store = new int[number];
	cout << "��������������ֹ�ͷ������(��ˡ�С�ˡ����⡢С��):" << endl;
	for (int i = 0; i < number; i++)
	{
		cin >> can[i];
	}
	//ÿ�ֹ�ͷ����������
	//lv\sv\lm\sm
	cost[0] = 6; cost[1] = 4;
	cost[2] = 9; cost[3] = 6;
	cout << "�������ͷ�ֿ�Ĺ�ͷ�洢" << endl;
	for (int i = 0; i < number; i++)
		cin >> store[i];
	/*store[0] = GetLargeVergetableaNum();
	store[1] = GetSmallVergetableNum();
	store[2] = GetLargeMeatNum();
	store[3] = GetSmallMeatNum();*/
	cout << "��Ϣ�������" << endl;
	//����õ�ÿ�ֹ�ͷ����Ҫ��ʱ�����ֵ���Ƕ�������������
	int temp;
	if (store[0] >= can[0])//�洢�Ĺ�ͷ��������Ҫ�Ķ�
		temp = 0;
	else
		temp = cost[0] * (can[0] - store[0]);
	//temp>=0ȷ��֮���ʱ�䲻����С��0
	for (int i = 1; i < number; i++)
		if (temp < cost[i] * (can[i] - store[i]))//��������Ҫʱ�����Ĺ�ͷ����
			temp = cost[i] * (can[i] - store[i]);
	for (int i = 0; i < number; i++)
		cout << can[i] << " " << cost[i] << " " << store[i] << endl;
	cout << "�����������ʱ��Ϊ:" << endl;
	cout << temp << endl;
	delete[]can;
	delete[]cost;
	delete[]store;
	this->day = temp;
	return this->day;
}

void Order2::ShowState() {
	//�����ǰ��״̬��Ϣ
	if (this->state->stateNum == 0)
		cout << "��" << this->GetCurrentay() << "�죺�����Ѿ�����" << endl;

	else if (this->state->stateNum == 1)
		cout << "��" << this->GetCurrentay() << "�죺������������" << endl;
		
	else
		cout << "��" << this->GetCurrentay() <<  "�충���Ѿ����" << endl;
}

