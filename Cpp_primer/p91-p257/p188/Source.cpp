using namespace std;
#include"iostream"

void reset(int *ip1,int *ip2) {
	int a;
	a = *ip1;
	*ip1 = *ip2;
	*ip2 = a;
}
int main() {
	int n = 0, i = 42;
	int &r = n;
	r = 42;
	r = i;
	i = r;
	cout << "n" << n << "i" << i << "r" << r;
	getchar();
	return 0;
}