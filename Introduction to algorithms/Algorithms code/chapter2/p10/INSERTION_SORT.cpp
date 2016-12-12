#include<iostream>
using namespace std;
//p10
void INSERTION_SORT(int* arr,const int sz) {
	for (int j = 1; j < sz; ++j) {
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
}
int main() {
	const int sz = 9;
	int a[sz] = { 9,8,7,6,5,4,3,2,1 };
	INSERTION_SORT(a, sz);
	for (int x = 0; x < sz; ++x)
		cout << a[x];
	getchar();
}