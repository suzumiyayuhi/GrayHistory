#pragma once
//16_28
#include<iostream>
#include<functional>
#include"DebugDelete.h"
using namespace std;
template<typename T> struct shared_ptrX
{
public:
	shared_ptrX() = default;
	shared_ptrX(T *a,function<void(T*)> d = DebugDelete(cout)) 
		:data(a), counter(new size_t(1)), Deleter(d) {}
	T& operator*() const { return *data; }
	T* operator->()const {return &(this->operator *());}
	~shared_ptrX()
	{
		decrement_destory();
	}
private:
	T *data;
	size_t *counter = new size_t(0);
	function<void(T*)> Deleter{ DebugDelete()};
	void decrement_destory();
};

template<typename T> void shared_ptrX<T>::decrement_destory() {
	if (data){
		if (--*counter == 0){
			Deleter(data);
			delete counter;
		}
		data = nullptr;
		counter = nullptr;
	}
}