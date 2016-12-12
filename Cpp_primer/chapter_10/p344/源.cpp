#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void X9_9(vector<string> &a) {
	sort(a.begin(), a.end());
	auto unique_back = unique(a.begin(), a.end());
	a.erase(unique_back, a.end());
	for (auto x : a)
		cout << x;
}
//10_10
//算法讲究适用性，方便使用在不同的地方。

int main() {
	vector<string> a = { "a","b","a","c","b" };
	X9_9(a);
	getchar();
	return 0;
}