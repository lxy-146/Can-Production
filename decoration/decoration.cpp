#include"decoration.h"
//��ͷ��װ�ӿ���ĳ�Ա������˵���Թ�ͷ�����˰�װ
void Can_pack::show() {
	//��ͷ��װ������˵����ζԹ�ͷ���а�װ
	can->show();
}
//�̳й�ͷ��װ�࣬����ͷ��װ��С��ͷ�ĳ�Ա����
void Small_Can::show() {
	can->show();
	//��ͷ��װ����
	pack(can);
}
//С��ͷ��װ����
void Small_Can::pack(Can* can) {
	cout << "(small)(ʹ�ð�װģʽ���Թ�ͷ���а�װ)" << endl;
}
//�̳й�ͷ��װ�࣬����ͷ��װ�ɴ��ͷ�ĳ�Ա����
void Big_Can::show() {
	can->show();
	pack(can);
}
//С��ͷ��װ����
void Big_Can::pack(Can* can) {
	cout << "(big)(ʹ�ð�װģʽ���Թ�ͷ���а�װ)" << endl;
}