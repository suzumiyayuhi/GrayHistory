#pragma once
#include<iostream>
using namespace std;
struct Foo {
public:
	Foo() :a("") { cout << "Foo()" << endl; }
	Foo(const string &str) :a(str) { cout << "Foo(const string &str)"<<endl; }
	Foo(const Foo &f) { a = f.a; cout << "Foo(const Foo &f)" << endl; }
	Foo(Foo &&f) { a = f.a; f.a = ""; cout << "Foo(Foo &&f)" << endl; }
//	Foo sorted() const & { cout << "sorted() const &" << endl; Foo ret(*this); return ret.sorted(); }
	Foo sorted() const & {cout << "sorted() &&"<<endl; return Foo(*this).sorted(); }
	//ÈÔÈ»ÊÇµÝ¹éËÀÑ­»·´íÎó
private:
	string a;
};
