#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
using namespace std::placeholders;
bool isShorter(string a,string::size_type sz) {
	return a.size() < sz;
}

void X10_22(vector<string> a) {
	int b;
	b = count_if(a.begin(), a.end(), bind(isShorter, _1,6));
	cout << b;
}

//X10_23
//至少一个
bool check_size(string a, string::size_type sz) {
	return a.size() > sz;
}

void X10_24(vector<string> tar,string a) {
	auto x = find_if(tar.begin(), tar.end(), bind(check_size, _1, a.size()));
	cout << *x;
}
void X10_25(vector<string> a,int sz) {
	auto begin = a.begin();
	while (begin!=a.end())
	{
		auto x = find_if(begin, a.end(), bind(check_size, _1, sz));
		cout << *x << " ";
		begin = x + 1;
	}
}

int main() {
	vector<string> a = { "sdw" ,"ssssssssssss","sxscqwed" };
//	X10_22(a);
//	X10_24(a, "sdwer");
	X10_25(a, 5);
	getchar();
	return 0;

}