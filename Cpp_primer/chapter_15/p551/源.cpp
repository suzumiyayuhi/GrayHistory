#include<iostream>
using std::cout;
using std::endl;
class Base {
public:
	virtual void fcn() { cout << "Base fcn()"<<endl; }
};
class D1 :public Base {
public:
	//15_23
	void fcn() override { cout << "D1 fcn()"<<endl; }
	//___________________________________
	virtual void f2() { cout << "D1 f2()" << endl; }
};
class D2 :public D1 {
public:
	void fcn(int) { cout << "D2 fcn(int)" << endl; }
	void fcn() override { cout << "D2 fcn()" << endl; }
	void f2() { cout << "D2 f2()" << endl; }
};
int main() {
	Base bobj; D1 dlobj; D2 d2obj;
	Base *bp1 = &bobj, *bp2 = &dlobj, *bp3 = &d2obj;
	bp1->fcn();//Base::fcn()
	bp2->fcn();//D1::fcn()
	bp3->fcn();//D2::fcn()

	D1 *d1p = &dlobj; D2 *d2p = &d2obj;
//	bp2->f2();
	d1p->f2();//D1::f2()
	d2p->f2();//D2::f2()

	Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
//	p1->fcn(42);缺少方法
//	p2->fcn(42);出错
	p3->fcn(42);//D2::fcn(int)
	getchar();
}