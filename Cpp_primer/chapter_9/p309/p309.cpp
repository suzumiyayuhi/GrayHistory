#include<string>
#include<deque>
#include<vector>
#include<iostream>
#include<list>
using namespace std;

void XX9_18() {
	string a;
	cin >> a;
	deque<string> x;
	x.push_back(a);
	auto y = a.begin();
	while (y!=a.end())
	{
		cout << *y;
		++y;
	}
}

void XX9_19() {
	string a;
	list<string> x;
	cin >> a;
	x.push_back(a);
	auto y = x.begin();
	while (y!=x.end())
	{
		cout << *y;
		++y;
	}
}

void XX9_20() {
	list<int> a{ 1,2,3,4,5 };
	deque<int> b;
	deque<int> c;
	for (auto x : a) {
		if (x/2==1)
		{
			b.push_back(x);
		}
		else
		{
			c.push_back(x);
		}
	}
	for (auto x : b)
		cout << x;
	cout << endl;
	for (auto x : c)
		cout << x;
}

int main() {
	XX9_20();
	getchar();
}