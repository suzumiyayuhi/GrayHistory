#pragma once
#include<iostream>
#include<string>
#include<memory>
#include<utility>
#include<initializer_list>
#include<algorithm>
//16_16
using namespace std;
template<typename T> struct Vec {
public:
	Vec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const Vec &);
	Vec(initializer_list<T> inistr);
	Vec& operator=(const Vec &);
	~Vec();
	void push_back(const T&);
	size_t size() const { return first_free - elements; }
	T* begin() const { return elements; }
	T* end() const { return first_free; }
	size_t capacity() const { return cap - elements; }
private:
	allocator<T> alloc;
	void chk_n_alloc() {
		if (size() == capacity())
			reallocate();
	}
	pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	T *elements;//指向数组首元素的指针
	T *first_free;//指向数组第一个空闲元素的指针
	T *cap;//指向数组尾后位置的指针
};



template<typename T> void Vec<T>::push_back(const T& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

template<typename T> pair<T*, T*> Vec<T>::alloc_n_copy(const T* begin, const T* end)
{
	auto data = alloc.allocate(end - begin);
	return make_pair(data,uninitialized_copy(begin,end,data));
}

template<typename T> Vec<T>::Vec(initializer_list<T> il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T> void Vec<T>::free() {
	if (elements) {
		auto temp = begin();
		for_each(elements, first_free, [this](T &rhs) {alloc.destroy(&rhs); });
	}
}

template<typename T> Vec<T>::Vec(const Vec& rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T> Vec<T>::~Vec()
{
	free();
}

template<typename T> Vec<T>& Vec<T>::operator=(const Vec& rhs)
{

	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

template<typename T> void Vec<T>::reallocate()
{
	auto NewCapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(NewCapacity);
	auto elem = elements;
	auto dest = newdata;
	for (auto i = 0; i != size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;	
	first_free = dest;
	cap = elements + NewCapacity;
}
