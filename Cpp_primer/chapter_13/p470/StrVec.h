#pragma once
#include<iostream>
#include<string>
#include<memory>
#include<utility>
#include<initializer_list>
using namespace std;
//13_39
//关于uninitialized_copy警告报错：调试->工程选项->代码生成->关闭安全检查
//将alloc的static属性删除

struct StrVec{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec &);
	//13_40
	StrVec(initializer_list<string> inistr);
	//__________________________________
	StrVec& operator=(const StrVec &);
	~StrVec();
	void push_back(const string&);
	size_t size() const { return first_free - elements; }
	string* begin() const{ return elements; }
	string* end() const{ return first_free; }
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
	string *elements;//指向数组首元素的指针
	string *first_free;//指向数组第一个空闲元素的指针
	string *cap;//指向数组尾后位置的指针
};




/*
#include <memory>
#include <string>
#include <initializer_list>

class StrVec {
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(std::initializer_list<std::string>);
	StrVec& operator=(const StrVec&);
	~StrVec();

	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }

	std::string& at(size_t pos) { return *(elements + pos); }
	const std::string& at(size_t pos) const { return *(elements + pos); }

	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count, const std::string&);

private:
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*,
		const std::string*);
	void free();
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	void reallocate();
	void alloc_n_move(size_t new_cap);
	void range_initialize(const std::string*, const std::string*);

private:
	std::string* elements;
	std::string* first_free;
	std::string* cap;
	std::allocator<std::string> alloc;
};
*/