#include<vector>
#include<iostream>
using namespace std;
int add1(int a, int b) {
	return a + b;
}
int minus1(int a, int b) {
	return a - b;
}
int multiply1(int a, int b) {
	return a * b;
}
int div1(int a, int b) {
	return a / b;
}
int main() {
	int a = 10, b = 2;
	int(*u)(int, int);
	int(*v)(int, int);
	int(*w)(int, int);
	int(*x)(int, int);
	u = add1; v = minus1; w = multiply1; x = div1;
	vector<int(*)(int,int)> qb{u, v, w, x};
	for (auto fk : qb) {
		cout << fk(a,b)<<endl;
	}
	getchar();
}