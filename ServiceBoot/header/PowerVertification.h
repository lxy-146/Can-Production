#ifndef POWER_VERTIFICATION_H
#define POWER_VERTIFICATION_H

/*
* ʵ��ģʽ��Interpreter Pattern
*/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <regex>
#include <set>


//������ʽ��
class Expression
{
public:
	virtual bool Interpret(const std::string& info) = 0;
};

//�ս�����ʽ��
class TerminalExpressin : public Expression
{
private:
	std::set<std::string> infos;

public:
	TerminalExpressin(const std::vector<std::string> datas);

	bool Interpret(const std::string& info);
};

//���ս�����ʽ��
class AndExpression : public Expression
{
private:
	std::shared_ptr<Expression> canType;
	std::shared_ptr<Expression> equipmentType;

public:
	AndExpression(std::shared_ptr<Expression> city, std::shared_ptr<Expression> person) : canType(city), equipmentType(person) {}

	bool Interpret(const std::string& info);
};

//������ȫ����Ϣ��
class ContextInterpreter {
private:
	std::vector<std::string> cans;
	std::vector<std::string> equipments;
	std::shared_ptr<Expression> smartAndExpr;

public:
	ContextInterpreter();

	void IsFree(const std::string& info);
};


#endif // !POWER_VERTIFICATION_H
#pragma once