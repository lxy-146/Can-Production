#include"PowerVertification.h"

//***********************Interpreter Pattern******************

//�ս�����ʽ��

TerminalExpressin::TerminalExpressin(const std::vector<std::string> datas)
{
	infos.insert(datas.begin(), datas.end());
}

bool TerminalExpressin::Interpret(const std::string& info)
{
	if (infos.find(info) != infos.end())
		return true;
	return false;
}

//���ս�����ʽ��

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


//������ȫ����Ϣ��
Context::Context()
{
	cans.push_back("Meat");
	cans.push_back("Vegetable");
	equipments.push_back("Processor");
	equipments.push_back("Productor");
	smartAndExpr = std::make_shared<AndExpression>(std::make_shared<TerminalExpressin>(cans), std::make_shared<TerminalExpressin>(equipments));
}

void Context::IsFree(const std::string& info)
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


//*****************************Test************************
//int main()
//{
//	std::shared_ptr<Context> bus = std::make_shared<Context>();
//	std::vector<std::string> passengers = { "Meat Processor" , "Vegetable Processor" , "Fruit Processor" , "Meat Productor" , "Vegetable Productor" , "Fruit Productor" };
//	for (std::string passenger : passengers)
//	{
//		bus->IsFree(passenger);
//	}
//
//	system("pause");
//	return 0;
//}