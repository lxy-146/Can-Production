/*
* PowerVertification.h - Definition
*/
//Interpreter Pattern

#include"PowerVertification.h"

//终结符表达式类
/*
* Function:终结符表达式类构造函数
*/
TerminalExpressin::TerminalExpressin(const std::vector<std::string> datas)
{
	infos.insert(datas.begin(), datas.end());
}

/*
* Function:终结符表达式类解释功能具体实现，判断是否在终结符数据集合中
*/
bool TerminalExpressin::Interpret(const std::string& info)
{
	if (infos.find(info) != infos.end())
		return true;
	return false;
}

//非终结符表达式类

/*
* Function:非终结符表达式类解释功能具体实现，接收需要解析的表达式，并添加AND处理逻辑
*/
bool AndExpression::Interpret(const std::string& info)
{
	std::regex pattern("\\s+");
	std::vector<std::string> results(std::sregex_token_iterator(info.begin(), info.end(), pattern, -1), std::sregex_token_iterator());
	if (results.size() != 2)
	{
		std::cout << "The input explanation information is wrong and cannot be resolved!" << std::endl;
		return false;
	}

	return canType->Interpret(results[0]) && equipmentType->Interpret(results[1]);
}


//上下文全局信息类
/*
* Function:上下文全局信息类构造函数
*/
ContextInterpreter::ContextInterpreter()
{
	cans.push_back("Meat");
	cans.push_back("Fruit");
	equipments.push_back("Processor");
	equipments.push_back("Productor");
	smartAndExpr = std::make_shared<AndExpression>(std::make_shared<TerminalExpressin>(cans), std::make_shared<TerminalExpressin>(equipments));
}

/*
* Function:验证生产设备是否可用
*/
void ContextInterpreter::IsFree(const std::string& info)
{
	if (smartAndExpr->Interpret(info))
	{
		std::cout << info << ",The machine started successfully." << std::endl;
	}
	else
	{
		std::cout << info << ",This machine does not exist! ------------ Cannot be resolved" << std::endl;
	}
}