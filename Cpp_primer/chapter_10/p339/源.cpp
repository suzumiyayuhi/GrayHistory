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
//���벻�����double����ת��Ϊint�����Ǿ��Ȼ��Ϊint

//10_5
//���Ϊ0
int main() {
	vector<int> a = { 1,2,3,4,5,6,7 };
	X10_3(a);
	getchar();
	return 0;
}