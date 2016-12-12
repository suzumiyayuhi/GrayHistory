#pragma once
#include<string>
#include<memory>
#include<vector>
using namespace std;

//12_32
//这类直接复制黏贴，估计已经不会写了2016.10.8，21:11
struct StrBlobptr;
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
	void check(vector<string>::size_type, const string &str) const;
};
StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> a) : data(make_shared<vector<string>>(a)) {}
string& StrBlob::front() const {
	return data->front();
}
string& StrBlob::back() const {
	return data->back();
}

struct StrBlobptr
{
public:
	StrBlobptr() :curr(0) {}
	StrBlobptr(StrBlob &a, size_t b = 0) :wptr(a.data), curr(b) {}

	bool operator!=(const StrBlobptr& p) { return p.curr != curr; }//github上的方法，重载了运算符

	string& deref() const;
	StrBlobptr& incr();//前缀递增
private:
	shared_ptr<vector<string>> check(const size_t sz) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
shared_ptr<vector<string>> StrBlobptr::check(const size_t sz) const {
	auto temp = wptr.lock();
	if (!temp)
	{
		throw runtime_error("Unbound StrBlobstr");
	}
	if (temp->size() < sz)
	{
		throw out_of_range("out of range");
	}
	return temp;
}
string& StrBlobptr::deref() const {
	auto temp = check(curr);
	return (*temp)[curr];
}
StrBlobptr& StrBlobptr::incr() {
	auto temp = check(curr);
	++curr;
	return *this;
}
StrBlobptr StrBlob::begin() {
	return StrBlobptr(*this, 0);
}
StrBlobptr StrBlob::end() {
	return StrBlobptr(*this, data->size());
}