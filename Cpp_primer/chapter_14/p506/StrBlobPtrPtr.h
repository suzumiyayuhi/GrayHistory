#pragma once
#include"StrBlobptr.h"
struct StrBlobPtrPtr
{
public:
	StrBlobPtrPtr(const StrBlobptr sbp) :wptr(make_shared<StrBlobptr>(sbp)) {};
	string& operator-> ()const;
private:
	shared_ptr<StrBlobptr> wptr;
};