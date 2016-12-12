#pragma once
#include<iostream>
using namespace std;
struct HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string& s = string());
	HasPtr(const HasPtr& hp);
	HasPtr(HasPtr&& p) noexcept;
//	HasPtr& operator=(HasPtr rhs);
	HasPtr& operator=(const HasPtr &rhs);
//	HasPtr& operator=(HasPtr &&rhs) noexcept;
	~HasPtr() {
		delete ps;
	}
private:
	string *ps;
	int i;
};
void swap(HasPtr &a, HasPtr &b) {
	using std::swap;
	swap(a.ps, b.ps);
	swap(a.i, b.i);
	cout << "swap(HasPtr &a,HasPtr &b)" << endl;
}
HasPtr::HasPtr(const string &s ) {
	ps = new string(s);
	i = 0;
	cout << "HasPtr(const string &s = string())" << endl;
}
HasPtr::HasPtr(const HasPtr &hp) {
	ps = new string(*hp.ps);
	i = hp.i;
	cout << "HasPtr(const HasPtr &hp)" << endl;
}
HasPtr::HasPtr(HasPtr &&p) noexcept {
	ps = p.ps;
	i = p.i;
	p.ps = nullptr;
	cout << "HasPtr(HasPtr &&p)" << endl;
}

/*
HasPtr& HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	cout << "HasPtr& HasPtr::operator=(HasPtr rhs)" << endl;
	return *this;
}*/


//13_53 and 13_54 ½â´ð


HasPtr& HasPtr::operator=(const HasPtr &rhs) {
	ps = new string(*rhs.ps);
	i = rhs.i;
	return *this;
	cout << "HasPtr& HasPtr::operator=(const HasPtr &rhs)" << endl;
}

/*
HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {
	ps = rhs.ps;
	i = rhs.i;
	rhs.ps = nullptr;
	cout << "HasPtr& HasPtr::operator=(HasPtr &&rhs)" << endl;
	return *this;
}*/