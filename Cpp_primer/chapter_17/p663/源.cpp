#include<iostream>
#include<random>
using namespace std;
//17_28
vector<unsigned> rt_rand() {
	static default_random_engine a;
	static uniform_int_distribution<unsigned> b(0, 10);
	vector<unsigned> tem;
	for (int i = 0; i < 10; ++i) {
		tem.push_back(b(a));
	}
	return tem;
}
//______________________________________________
//17_29
vector<unsigned> rt_rand(const unsigned &x,const unsigned &y) {
	static default_random_engine a;
	static uniform_int_distribution<unsigned> b(x,y);
	vector<unsigned> tem;
	for (int i = 0; i < 10; ++i) {
		tem.push_back(b(a));
	}
	return tem;
}
//______________________________________________
//17_30
vector<unsigned> rt_rand(const unsigned &x, const unsigned &y,const int &sw1,const int &sw2) {
	static default_random_engine a;
	static uniform_int_distribution<unsigned> b(x, y);
	vector<unsigned> tem;
	for (int i = 0; i < 10; ++i) {
		tem.push_back(b(a));
	}
	if (sw1) {
		cout << "max:" << y<<" ";
	}
	if (sw2) {
		cout << "min:" << x<<" ";
	}
	return tem;
}
//______________________________________________

int main() {
	vector<unsigned> a = rt_rand();
	for (auto x : a)
		cout << x;
	getchar();
}