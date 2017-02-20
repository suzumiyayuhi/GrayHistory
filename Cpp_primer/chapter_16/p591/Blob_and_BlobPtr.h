#pragma once
//16_12
#include<vector>
#include<initializer_list>
#include<memory>
using namespace std;
template<typename T> struct Blob {
public:
	Blob() = default;
	Blob(initializer_list<T> il);
	size_t size() { return data->size(); }
	bool empty() { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
private:
	shared_ptr<vector<T>> data;
	void check(size_t i, const string &msg) const;
};

template<typename T> Blob<T>::Blob(initializer_list<T> il) :
	data(make_shared<vector<T>>(il)) {
}

template<typename T>
void Blob<T>::check(size_t i, const string & msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}


template<typename T> struct BlobPtr {
public:
	BlobPtr() :curr(0) {}
	BlobPtr(const Blob &b) :wptr(b.data), curr(0) {}
private:
	shared_ptr<vector<T>> check(const size_t sz) const;
	weak_ptr<vector<T>> wptr;
	size_t curr;
};