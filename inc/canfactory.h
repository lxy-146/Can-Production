#ifndef CANFACTORY_H
#define CANFACTORY_H

#include"header.h"

/// <summary>
/// ����ģʽ����ͷ�ӹ���
/// </summary>
class can_factory {
private:
	static can_factory* canfactory;
	can_factory(){}
public:
	static can_factory* GetInstance();
};

#endif // !CANFACTORY_H

#pragma once
