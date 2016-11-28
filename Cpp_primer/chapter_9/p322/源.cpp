#include<vector>
#include<string>
#include<iostream>
using namespace std;
void X9_41() {
	vector<char> xx{ 's','d','c' };
	string yy(xx.data(), xx.size());
	cout << yy;
	getchar();
}
//9_42
//用reserve一次性为string分配100个字符空间，用push_back将元素添加至尾部。
int main() {
	X9_41();
	return 0;
}