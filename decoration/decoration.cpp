#include"decoration.h"
void Can_pack::show() {
	can->show();
}
void Small_Can::show() {
	can->show();
	pack(can);
}
void Small_Can::pack(Can* can) {
	cout << "(small)" << endl;
}
void Big_Can::show() {
	can->show();
	pack(can);
}
void Big_Can::pack(Can* can) {
	cout << "(big)" << endl;
}