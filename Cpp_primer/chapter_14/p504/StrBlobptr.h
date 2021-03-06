#pragma once
#include"StrBlob.h"
struct StrBlobptr
{
public:
	StrBlobptr() :curr(0) {}
	StrBlobptr(StrBlob &a, size_t b = 0) :wptr(a.data), curr(b) {}
	//14_28
	friend StrBlobptr& operator+(StrBlobptr& str, int n);
	friend StrBlobptr& operator-(StrBlobptr& str, int n);
	//___________________________________________________________
	bool operator!=(const StrBlobptr& p) { return p.curr != curr; }
	//14_27
	StrBlobptr& operator++();
	StrBlobptr& operator--();
	StrBlobptr& operator++(int);
	StrBlobptr& operator--(int);
	//________________________________
	string& deref() const;
	StrBlobptr& incr();
private:
	shared_ptr<vector<string>> check(const size_t sz) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};