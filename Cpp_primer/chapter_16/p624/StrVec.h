#pragma once
#include<iostream>
#include<string>
#include<memory>
#include<utility>
#include<initializer_list>
using namespace std;
struct StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec &);
	StrVec(initializer_list<string> inistr);
	StrVec& operator=(const StrVec &);
	~StrVec();
	void push_back(const string&);
	size_t size() const { return first_free - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count, const string& s);
	//16_58
	template<typename ...T>
	void emplace_back(const T& ...ts) {
		chk_n_alloc();
		alloc.construct(first_free++,forward<T>(ts...));
	}
	//__________________________________________________
private:
	allocator<string> alloc;
	void chk_n_alloc() {
		if (size() == capacity())
			reallocate();
	}
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string *elements;//指向数组首元素的指针
	string *first_free;//指向数组第一个空闲元素的指针
	string *cap;//指向数组尾后位置的指针
};