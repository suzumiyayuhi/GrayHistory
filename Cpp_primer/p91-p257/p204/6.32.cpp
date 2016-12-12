#include"iostream"
using namespace std;
int &get(int *arry, int index) {
	return arry[index];
}
int main1() {
	int ia[10];
	for (int i = 0; i != 10; ++i) {
		get(ia, i) = i;
	}
	for (auto vv : ia)
		cout << vv;
	getchar();
	return 0;
}