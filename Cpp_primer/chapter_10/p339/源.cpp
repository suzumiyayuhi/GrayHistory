#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>
#include<list>
using namespace std;
void X10_3(vector<int> a) {
	int sum = 0;
	sum = accumulate(a.begin(), a.end(),0);
	if (sum)
	{
		cout << sum;
	}
}
//10_4
//编译不会出错，double可以转换为int，但是精度会变为int

//10_5
//结果为0
int main() {
	vector<int> a = { 1,2,3,4,5,6,7 };
	X10_3(a);
	getchar();
	return 0;
}