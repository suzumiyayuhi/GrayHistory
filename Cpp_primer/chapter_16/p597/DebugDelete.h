#pragma once
#include<iostream>
using namespace std;
//16_21
struct DebugDelete {
public:
	template<typename T> void operator()(T *p) {
		cout << "deleting point";
		delete p;
	}
};
//___________________________________________________________