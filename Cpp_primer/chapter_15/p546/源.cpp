//15_18
/*
Base *p = &dl; 正确
p=&d2;错误
p=&d3;错误
p=&dd1;正确
p=&dd2;错误
p=&dd3;错误
*/
//作为派生类的用户,只有当派生类的继承关键字为public时才可以成功将派生类转化至基类

//15_19
//Derived_from_private:public Priv_Derv类不合法

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
	//void memfcn(Base &b) { b = *this; } 不合法
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
//	p = &d2;错误
//	p = &d3;错误
	p = &dd1;
//	p = &dd2;错误
//	p = &dd3;错误
}
//——————————————————————————————————————-
