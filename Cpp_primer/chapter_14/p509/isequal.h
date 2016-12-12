#pragma once
#include<iostream>
#include<string>
using namespace std;
//14_38
struct isequal {
public:
	isequal(size_t s) :sz(s) {}
	bool operator()(string &str) {
		return str.size() == sz;
	}
private:
	size_t sz;
};