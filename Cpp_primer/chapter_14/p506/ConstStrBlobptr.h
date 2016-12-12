#pragma once
#include"StrBlob.h"
struct ConstStrBlobPtr
{
public:
	ConstStrBlobPtr(const StrBlob &a) :wptr(a.data), curr(0) {}
	ConstStrBlobPtr() :curr(0) {}
	bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }//github上的方法，重载了运算符
	const string& operator*()const;
	const string& operator->()const;
	const string& deref() const;
	ConstStrBlobPtr& incr();//前缀递增
private:
	shared_ptr<vector<string>> check(size_t sz) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};