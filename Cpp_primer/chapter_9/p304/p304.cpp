#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;
int main() {
	list<char *> x{"sssd"};
	vector<string> y;
	y.assign(x.cbegin(),x.cend());
	for (auto a : y)
		cout << a;
	cout << y.max_size();
	getchar();
	return 0;
}