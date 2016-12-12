#pragma once
#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace std;
//14_16
struct StrBlob
{
public:
	friend struct StrBlobptr;
	friend struct ConstStrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
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
	void check(vector<string>::size_type, const string &str) const;
};