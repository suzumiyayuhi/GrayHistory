//14_50
struct LonDouble {
	LonDouble(double = 0.0);
	operator double();
	operator float();
};
LonDouble ldObj;
//int ex1 = ldObj;//����
//float ex2 = ldObj;��ȷ
//��������������������������������������������

//14_51
void calc(int);
void calc(LonDouble);
double dval;
int main() {
	calc(dval);
	//double->int�ɱ�׼�ⶨ��ת������,���ȼ������Զ���ת��
}
//___________________________________________________