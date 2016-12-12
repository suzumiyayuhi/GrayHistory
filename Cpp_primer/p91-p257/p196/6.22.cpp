#include"iostream"
#include"string"
using namespace std;

int exchange(int *a,int *b,int &d) {
	d = *a;
	a = b;
	return *a;
}

int main2() {
	int *a, *b;
	int c = 5, d = 9;
	int e;
	a = &c;
	b = &d;

	*a=exchange(a, b,e);
	b = &e;

	cout << *a << *b;
	getchar();
	return 0;
}