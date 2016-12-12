#include"iostream"
using namespace std;

int com1(int a,int *b){
	if (a > *b)
		return a;
	else
		return *b;
}
int main1() {
	int a = 40, b = 20;
	int *c;
	c = &b;
	int d = com1(a, c);
	cout << d;
	getchar();
	return 0;
}