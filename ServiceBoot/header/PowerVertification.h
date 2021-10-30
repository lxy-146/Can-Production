#ifndef POWER_VERTIFICATION_H
#define POWER_VERTIFICATION_H

/*
* 实现模式：Interpreter Pattern
*/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <regex>
#include <set>


//抽象表达式类
class Expression
{
public:
	virtual bool Interpret(const std::string& info) = 0;
};

//终结符表达式类
class TerminalExpressin : public Expression
{
private:
	std::set<std::string> infos;

public:
	TerminalExpressin(const std::vector<std::string> datas);

	bool Interpret(const std::string& info);
};

//非终结符表达式类
class AndExpression : public Expression
{
private:
	std::shared_ptr<Expression> canType;
	std::shared_ptr<Expression> equipmentType;

public:
	AndExpression(std::shared_ptr<Expression> city, std::shared_ptr<Expression> person) : canType(city), equipmentType(person) {}

	bool Interpret(const std::string& info);
};

//上下文全局信息类
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