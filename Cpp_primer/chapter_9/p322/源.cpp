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
//��reserveһ����Ϊstring����100���ַ��ռ䣬��push_back��Ԫ�������β����
int main() {
	X9_41();
	return 0;
}