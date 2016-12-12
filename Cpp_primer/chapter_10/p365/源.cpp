#include<vector>
#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;
void X10_34(vector<string> a) {
	ostream_iterator<string> OS(cout, " ");
	copy(a.rbegin(), a.rend(), OS);
}
void X10_35(vector<string> a) {
	ostream_iterator<string> OS(cout, " ");
	copy(a.begin(), a.end(), OS);
}
void x10_36(vector<int> a) {
	auto the = find(a.rbegin(), a.rend(), 0);
}
void x10_37(vector<int> a) {
	sort(a.rbegin() + 3, a.rend() - 2);
	for (auto x : a)
		cout << x;
}

int main() {
	vector<string> a = { "sd","fff","vvv" };
	vector<int> b = { 1,2,3,4,5,6,7,8,9,0 };
	x10_37(b);
	getchar();
	return 0;
}