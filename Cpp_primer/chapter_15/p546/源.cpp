//15_18
/*
Base *p = &dl; ��ȷ
p=&d2;����
p=&d3;����
p=&dd1;��ȷ
p=&dd2;����
p=&dd3;����
*/
//��Ϊ��������û�,ֻ�е�������ļ̳йؼ���Ϊpublicʱ�ſ��Գɹ���������ת��������

//15_19
//Derived_from_private:public Priv_Derv�಻�Ϸ�

//15_20
class Base {
	void memfcn(Base &b) { b = *this; }
};
struct Pub_Derv :public Base {
	void memfcn( Base &b){b = *this; }
};
struct Priv_Derv:private Base{
	void memfcn(Base &b) { b = *this; }
};
struct Port_Derv :protected Base {
	void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Public :public Pub_Derv{
	void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private:public Priv_Derv{
	//void memfcn(Base &b) { b = *this; } ���Ϸ�
};
struct Derived_from_Procted :public Port_Derv {
	void memfcn(Base &b) { b = *this; }
};
int main() {
	Pub_Derv d1;
	Priv_Derv d2;
	Port_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Procted dd3;
	Base *p = &d1;
//	p = &d2;����
//	p = &d3;����
	p = &dd1;
//	p = &dd2;����
//	p = &dd3;����
}
//����������������������������������������������������������������������������-
