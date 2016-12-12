#include"StrVec.h"
#include<algorithm>
using namespace std;

void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
pair<std::string*, string*> StrVec::alloc_n_copy(const string* begin, const string* end)
{
	auto data = alloc.allocate(end - begin);
	return{ data,uninitialized_copy(begin,end,data) };
}
//13_40
StrVec::StrVec(initializer_list<string> il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
//________________________________________________________
/*void StrVec::free()
{
if (elements) {
for (auto x = first_free; x != elements;)
alloc.destroy(--x);
alloc.deallocate(elements, cap-elements);
}
}*/
void StrVec::free() {		//重写版本
	if (elements) {
		auto temp = begin();
		for_each(elements, first_free, [this](string &rhs) {alloc.destroy(&rhs); });
	}//for_each用法不熟悉，此段照抄
}
StrVec::StrVec(const StrVec& rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::~StrVec()
{
	free();
}
StrVec& StrVec::operator=(const StrVec& rhs)
{

	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}
void StrVec::reallocate()
{
	auto NewCapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(NewCapacity);
	auto elem = elements;
	auto dest = newdata;
	for (auto i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();//释放旧内存空间
	elements = newdata;		//原错误 elem
	first_free = dest;
	cap = elements + NewCapacity;
}
void StrVec::reserve(size_t new_cap) {
	if (capacity() <= new_cap) {
		auto newdata = alloc.allocate(new_cap);
		auto elem = elements;
		auto dest = newdata;
		for (auto i = 0; i != size(); ++i) {
			alloc.construct(dest++, move(*elem++));
		}
		free();
		elements = newdata;	//原错误 elem
		first_free = dest;
		cap = elements + new_cap;
	}
}
void StrVec::resize(size_t rsz) {
	resize(rsz, "");
}
void StrVec::resize(size_t rsz, const string &str) {
	if (size() <= rsz)
	{
		for (size_t a = size(); a != rsz; a++)
			push_back(str);
	}
	else
	{
		for (size_t a = size(); a != rsz; a--)
		{
			alloc.destroy(--first_free);
		}
	}
}
bool operator==(const StrVec &a, const StrVec &b) {
	return equal(a.begin(), a.end(), b.begin()) && a.size() == b.size();
}
bool operator!=(const StrVec &a, const StrVec &b) {
	return !(a == b);
}
bool operator<(const StrVec &a, const StrVec &b) {
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}
bool operator>(const StrVec &a, const StrVec &b) {
	return b<a;
}
bool operator<=(const StrVec &a, const StrVec &b) {
	return !(b < a);
}
bool operator>=(const StrVec &a, const StrVec &b) {
	return !(a < b);
}