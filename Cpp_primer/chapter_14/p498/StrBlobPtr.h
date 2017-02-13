#pragma once
#include"StrBlob.h"
using namespace std;
struct StrBlobptr
{
public:
	friend struct StrBlob;
	StrBlobptr() :curr(0) {}
	StrBlobptr(StrBlob &a, size_t b = 0) :wptr(a.data), curr(b) {}

	bool operator!=(const StrBlobptr& p) { return p.curr != curr; }

	string& deref() const;
	StrBlobptr& incr();//Ç°×ºµÝÔö
private:
	shared_ptr<vector<string>> check(const size_t sz) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
