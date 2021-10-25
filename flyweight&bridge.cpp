// flyweight.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <vector>
#include "flyweight.h"
using namespace std;

int main()
{
    Kind *kind1=new BeefKind();
    Kind *kind2=new PorkKind();
    Kind *kind3=new FishKind();

    newCan *newMiddleCan = new MiddleCan();
    newMiddleCan->produceSize(kind1);
    newMiddleCan->produceSize(kind2);
    Factory* factory = new Factory();
    vector<Can*>pool;
    for (int i = 0; i <= 20; i++) {
        Can* f;
        int temp =1;
        switch (temp) {
        case 1:
            f = factory->GetFlyweights("水果大罐头");
            f->produce(i);
            break;
        case 2:
            f = factory->GetFlyweights("水果小罐头");
            f->produce(i);
            break;
        case 3:
            f = factory->GetFlyweights("肉大罐头"); 
            f->produce(i);
            break;
        case 4:
            f = factory->GetFlyweights("肉小罐头"); 
            f->produce(i);
            break;
        }
        pool.push_back(f);
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
