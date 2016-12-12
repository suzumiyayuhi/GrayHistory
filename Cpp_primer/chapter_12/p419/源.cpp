#include<iostream>
#include<memory>
using namespace std;
//12_16
/*
void dd() {
	unique_ptr<int> d(new int(2));
	unique_ptr<int> c(new int(3));
	d = c;
}*/
//严重性	代码	说明	项目	文件	行	禁止显示状态
//错误(活动)		无法引用 函数 "std::unique_ptr<_Ty, _Dx>::operator=(const std::unique_ptr<_Ty, _Dx>::_Myt &) [其中 _Ty=int, _Dx=std::default_delete<int>]"
//(已声明 所在行数 : 1436，所属文件 : "c:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\memory") --它是已删除的函数	
//p419	d : \C++_primer\chapter_12\p419\p419\源.cpp	9
//______________________________________________________________________________________

int main() {
	int ix=1024,*pi=&ix,*pi2=new int(2048);
	typedef unique_ptr<int> Intp;
	//12_17
	//Intp po(ix); ix为int类型，无法进行构造
	//Intp p1(pi);编译通过，运行出错。p1销毁时同时释放pi，其行为是未定义的
	//Intp p2(pi2);正确
	//Intp p3(&ix);编译通过，运行出错。p1销毁时同时释放pi，其行为是未定义的
	//Intp p4(new int(2048));正确
	//Intp p5(p2.get());编译通过，运行出错。p2.get返回内置指针，当p2被销毁时p5变成空悬指针，
	//____________________________________________________________________________________________________
	getchar();
	return 0;
}
//12_18
//没有必要提供release成员，shared_ptr可以进行简单的复制和拷贝操作