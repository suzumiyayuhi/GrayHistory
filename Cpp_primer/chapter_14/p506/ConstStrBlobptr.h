#pragma once
#include"StrBlob.h"
struct ConstStrBlobPtr
{
public:
	ConstStrBlobPtr(const StrBlob &a) :wptr(a.data), curr(0) {}
	ConstStrBlobPtr() :curr(0) {}
	bool operator!=(const ConstStrBlobPtr& p) { return p.curr != curr; }//github�ϵķ����������������
	const string& operator*()const;
	const string& operator->()const;
	const string& deref() const;
	ConstStrBlobPtr& incr();//ǰ׺����
private:
	shared_ptr<vector<string>> check(size_t sz) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};