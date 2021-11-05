/*
* PowerVertification.h - Definition
*/
//Interpreter Pattern

#include"PowerVertification.h"

//�ս�����ʽ��
/*
* Function:�ս�����ʽ�๹�캯��
*/
TerminalExpressin::TerminalExpressin(const std::vector<std::string> datas)
{
	infos.insert(datas.begin(), datas.end());
}

/*
* Function:�ս�����ʽ����͹��ܾ���ʵ�֣��ж��Ƿ����ս�����ݼ�����
*/
bool TerminalExpressin::Interpret(const std::string& info)
{
	if (infos.find(info) != infos.end())
		return true;
	return false;
}

//���ս�����ʽ��

/*
* Function:���ս�����ʽ����͹��ܾ���ʵ�֣�������Ҫ�����ı��ʽ�������AND�����߼�
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


//������ȫ����Ϣ��
/*
* Function:������ȫ����Ϣ�๹�캯��
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
* Function:��֤�����豸�Ƿ����
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