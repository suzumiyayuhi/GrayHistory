#pragma once
#include<iostream>
struct DebugDelete {
public:
	DebugDelete(std::ostream &a):os(a){}
	template<typename T> void operator()(T *t) {
		os << "deleting" << std::endl;
		delete t;
	}
private:
	std::ostream& os;
};