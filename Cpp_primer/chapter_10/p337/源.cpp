#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
void X10_1(vector<int> a,int val) {
	int result;
	result = count(a.begin(), a.end(), val);
	if (result)
	{
		cout << result;
	}
}
void X10_2(vector<string> a, string val) {
	int result;
	result = count(a.begin(), a.end(), val);
	if (result)
	{
		cout << result;
	}
}

int main() {
	vector<int> a1 = { 123,5,23,5,7,3,3,22 };
	int val1 = 3;
	X10_1(a1, val1);
	getchar();
	return 0;
}