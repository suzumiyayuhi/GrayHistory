//13_45
//右值引用绑定一个临时对象
//左值引用绑定一个存在时间稍长的对象

//13_46
//int f();
//vector<int> vi(100);
//int &&r1=f();
//int &r2=vi[0];
//int &r3=r1;
//int &&r4=vi[0]*f();
#include"String.h"
int main() {
	String a("ddd");
	a.push_back("sww");
	getchar();
}