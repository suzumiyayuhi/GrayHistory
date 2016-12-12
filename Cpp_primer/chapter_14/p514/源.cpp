#include<iostream>
#include<map>
#include<string>
#include<functional>
using namespace std;
int main() {
	string s;
	int left, right;
	map<string, function<int(int, int)>> cal;
	cal.insert({ "+",[](int a,int b) {return a + b; } });
	cal.insert({ "-",[](int a,int b) {return a - b; } });
	cal.insert({ "*",[](int a,int b) {return a * b; } });
	cal.insert({ "/",[](int a,int b) {return a / b; } });
	while (cin >> left >> s >> right) {
		cout << cal[s](left, right) << endl << endl << endl;
	}
	return 0;
}