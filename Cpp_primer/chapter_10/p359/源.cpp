#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
#include<list>
#include<deque>
using namespace std;
//10_26
//back_inserter������һ��ʹ��push_back�ĵ������������õ�����ʱ������push_back����
//front_inserter��ͬ�ϣ�����push_front����
//inserter��ͬ�ϣ�����insert����

void X10_27(vector<string> &a,list<string> b) {
	sort(a.begin(), a.end());
	unique_copy(a.begin(), a.end(), back_inserter(b));
	for (auto xx : b)
		cout << xx<<" " ;
}
void X10_28() {
	vector<int> a = { 1,2,3,4,5,6,7,8,9 };
	list<int>b;
	list<int>c;
	list<int>d;
	auto begin = a.begin();
	while (begin!=a.end())
	{
		back_inserter(b) = *begin;
		front_inserter(c) = *begin;
		inserter(d,d.begin()) = *begin;
		++begin;
	}
	for (auto x : b)
		cout << x;
	cout << endl;
	for (auto x : c)
		cout << x;
	cout << endl;
	for (auto x : d)
		cout << x;
	//123456789
	//987654321
	//987654321
}

int main() {
	vector<string> a = { "ddw","feg","ddw","ve" };
	list<string> b;
//	X10_27(a,b);
	X10_28();
	getchar();
	return 0;
}