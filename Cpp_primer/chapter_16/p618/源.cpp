#include<iostream>
#include<sstream>
using namespace std;
//16_48
template<typename T>
string debug_rep(const T &data) {
	ostringstream oss;
	oss << data;
	return oss.str();
}
//______________________________________

//16_49&&16_50
template<typename T>
void f(T data) {
	cout << "template<typename T> void f(T)" << endl;
}

template<typename T>
void f(const T *data) {
	cout << "template<typename T> void f(const T *data)" << endl;
}

template<typename T>
void g(T data) {
	cout << "template<typename T> void g(T data)" << endl;
}

template<typename T>
void g(T *data) {
	cout << "template<typename T> void g(T *data)" << endl;
}
//________________________________________________________

int main() {
	cout<<debug_rep(1);
	cout << endl;

	int i = 42; 
	int *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42); g(p); g(ci); g(p2);
	f(42); f(p); f(ci); f(p2);
	getchar();
}