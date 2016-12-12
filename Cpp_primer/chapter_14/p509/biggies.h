#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct biggies1{
public:
	bool operator()(const string &a, const string &b) {
		return a.size() < b.size();
	}
};
struct biggies2 {
public:
	biggies2(size_t n) :sz(n) {}
	bool operator()(const string &str) {
		return str.size() >= sz;
	}
private:
	size_t sz;
};
struct biggies3
{
public:
	void operator()(const string &str) {
		cout << str << " ";
	}
};