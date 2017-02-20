#include<iostream>
#include<utility>
using namespace std;
//16_47
void m(int &a,int &b) {
	++a; ++b;
	cout << a << " " << b << endl;
}

void n(int &&a, int &&b) {
	++a, ++b;
	cout << a << " " << b << endl;
}

template<typename T1,typename T2,typename T3>
void filp1(T1 fun,T2 &d1,T3 &d2) {
	cout << "filp1:";
	fun(d1, d2);
}

template<typename T1,typename T2,typename T3>
void filp2(T1 fun, T2 &d1, T3 &d2) {
	cout << "filp2:";
	fun(forward<T2> (d1),forward<T3> (d2));
}

int main() {
	int a = 5, b = 8;
	const int c = 3;
	cout << "origin:" << a << " " << b << endl;
	filp1(m, a, b);
	filp2(n, a, b);
	cout << "final:" << a << " " << b << endl;
	getchar();
}