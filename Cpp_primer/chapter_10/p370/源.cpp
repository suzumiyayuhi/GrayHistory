#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;
void X10_42(list<string> &tar) {
	tar.sort();
	tar.unique();
	for (auto x : tar)
		cout << x <<" ";
}
int main() {
	list<string> a = { "ss","c","ss","d","c" };
	X10_42(a);
	getchar();
	return 0;
}