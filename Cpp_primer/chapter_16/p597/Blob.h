#pragma once
#include<vector>
#include<initializer_list>
#include<memory>
using namespace std;
template<typename T> struct Blob {
public:
	Blob() = default;
	Blob(initializer_list<T> il);
	//16_24
	Blob(T *beg, T *end):data(new vector<string>()) {
		for (auto tem = beg; tem != end; ++tem) {
			data->push_back(*tem);
		}
	}
	//_________________________________________
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