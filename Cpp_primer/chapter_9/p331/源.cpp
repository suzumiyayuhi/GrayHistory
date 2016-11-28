#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
void X9_52(string a) {
	stack<char> val;
	int first, last;
	first = a.find_first_of('(');
	last = a.find_last_of(')');
	while (first!=last-1)
	{
		val.push(a[last-1]);
		--last;
	}

	while (!val.empty())
	{
		cout << val.top();
		val.pop();
	}
}
int main() {
	string a = "(23)";
	X9_52(a);
	getchar();
	return 0;
}