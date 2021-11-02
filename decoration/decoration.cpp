#include"decoration.h"
//罐头包装接口类的成员函数，说明对罐头进行了包装
void Can_pack::show() {
	//罐头包装函数，说明如何对罐头进行包装
	can->show();
}
//继承罐头包装类，将罐头包装成小罐头的成员函数
void Small_Can::show() {
	can->show();
	//罐头包装函数
	pack(can);
}
//小罐头包装函数
void Small_Can::pack(Can* can) {
	cout << "(small)(使用包装模式，对罐头进行包装)" << endl;
}
//继承罐头包装类，将罐头包装成大罐头的成员函数
void Big_Can::show() {
	can->show();
	pack(can);
}
//小罐头包装函数
void Big_Can::pack(Can* can) {
	cout << "(big)(使用包装模式，对罐头进行包装)" << endl;
}