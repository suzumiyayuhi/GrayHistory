#pragma once
#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include<initializer_list>
using namespace std;
struct StrBlob
{
public:
	friend struct StrBlobptr;
	friend struct ConstStrBlobPtr;
	StrBlob();
	StrBlob(initializer_list<string>);
	vector<string>::size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &a) { return data->push_back(a); }
	void pop_back(const string &a);
	string& front() const;
	string& back() const;
	StrBlobptr begin();
	StrBlobptr end();
private:
	shared_ptr<vector<string>> data;
	void check(size_t i, const string &str) const {
		if (i >= data->size()) {
			throw out_of_range("out of range");
		}
	}
};