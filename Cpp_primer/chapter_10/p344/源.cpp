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
//�㷨���������ԣ�����ʹ���ڲ�ͬ�ĵط���

int main() {
	vector<string> a = { "a","b","a","c","b" };
	X9_9(a);
	getchar();
	return 0;
}