#pragma once
//14_37
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Equalif {
public:
	Equalif(string t1) :key(t1) {}
	bool operator()(string);
private:
	string key;
};
bool Equalif::operator()(string tar) {
	return tar == key;
}