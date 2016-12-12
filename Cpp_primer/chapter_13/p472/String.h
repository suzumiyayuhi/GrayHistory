#pragma once
#include<iostream>
#include<memory>
using namespace std;
struct String {
public:
	//13_47
	String() :elements(nullptr), cap(nullptr) { cout << "String()" << endl; }
	String(char *);
	void push_back(char *ch);
	size_t capacity();
	size_t size();
private:
	void reallocate();
	void chk_n_alloc() {
		if (size() == capacity())
			reallocate();
	}
	allocator<char> alloc;
	char *elements;
	char *cap;
};
void String::reallocate() {
	auto newsize = size() ? size() * 2 : 1;
	auto newdata = alloc.allocate(newsize);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	elements = newdata;
	cap = dest;
}
size_t String::capacity() {
	return cap - elements;
}
size_t String::size() {
	return cap - elements - 1;
}
String::String(char *chs) {
	auto tempc = chs;
	while (*chs)
		++chs;
	auto newdata = alloc.allocate(++chs - tempc);
	auto newdata1 = uninitialized_copy(tempc, chs, newdata);
	elements = newdata;
	cap = newdata1;
	cout << "String(char *chs)" << endl;
}
void String::push_back(char *ch) {
	chk_n_alloc();
	while(*ch)
		alloc.construct(cap--, *ch++);
}