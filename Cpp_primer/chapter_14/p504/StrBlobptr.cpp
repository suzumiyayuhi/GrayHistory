#include"StrBlobptr.h"
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
StrBlobptr& StrBlobptr::operator++() {
	check(curr);
	++curr;
	return *this;
}
StrBlobptr& StrBlobptr::operator--() {
	check(curr);
	--curr;
	return *this;
}
StrBlobptr& StrBlobptr::operator++(int a) {
	auto temp = *this;
	++*this;
	return temp;
}
StrBlobptr& StrBlobptr::operator--(int a) {
	auto temp = *this;
	--*this;
	return *this;
}
//14_28
StrBlobptr& operator+(StrBlobptr &strbp,int n) {
	auto temp = strbp;
	strbp.curr += n;
	return temp;
}
StrBlobptr& operator-(StrBlobptr &strbp, int n) {
	auto temp = strbp;
	strbp.curr -= n;
	return temp;
}
//__________________________________________________