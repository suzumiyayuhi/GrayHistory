#include"ConstStrBlobptr.h"
shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t sz) const {
	auto temp = wptr.lock();
	if (!temp) {
		throw runtime_error("Unbound StrBlobstr");
	}
	if (curr>temp->size)
	{
		throw out_of_range("curr is out of range");
	}
	return temp;
}
const string& ConstStrBlobPtr::deref() const {
	auto temp = check(curr);
	return (*temp)[curr];
}
ConstStrBlobPtr& ConstStrBlobPtr::incr() {
	++curr;
	return *this;
}
//14_30
const string& ConstStrBlobPtr::operator*()const{
	auto p = check(curr);
	return (*p)[curr];
}
const string& ConstStrBlobPtr::operator->() const {
	return this->operator*();
}
//_______________________________________________________