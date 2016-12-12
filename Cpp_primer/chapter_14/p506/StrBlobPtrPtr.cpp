#include"StrBlobPtrPtr.h"
//14_32
string& StrBlobPtrPtr::operator->()const {
	return wptr->operator->();
}