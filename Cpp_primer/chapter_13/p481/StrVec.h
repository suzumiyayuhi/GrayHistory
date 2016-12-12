#pragma once
#include<iostream>
#include<utility>
#include<vector>
using namespace std;
struct StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec &);
	StrVec(initializer_list<string> inistr);
	StrVec& operator=(const StrVec &);
	StrVec& operator=(StrVec &&);
	StrVec(StrVec&&);
	~StrVec();
	void push_back(const string&);
	size_t size() const { return first_free - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count, const string& s);
private:
	allocator<string> alloc;
	void chk_n_alloc() {
		if (size() == capacity())
			reallocate();
	}
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string *elements;//ָ��������Ԫ�ص�ָ��
	string *first_free;//ָ�������һ������Ԫ�ص�ָ��
	string *cap;//ָ������β��λ�õ�ָ��
};