#include"iostream"
using namespace std;
void reset1(int &i) {
	i = 9;
}
int main1() {
	int a = 5;
	reset1(a);
	cout << a;
	getchar();
	return 0;
}