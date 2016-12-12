#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void X10_20(vector<string> a) {
	int counter;
	counter = count_if(a.begin(), a.end(), [](string a) {return a.size() > 5; });
	cout << counter;
}
void X10_21() {
	int temp = 20;
	auto f = [&temp] () -> bool
	{
			while (temp!=0)
		{
				--temp;
		}
	return true;
	};
	if (f())
	{
		cout << "sdqwqwrqwe";
	}
}

int main() {
	vector<string> a = { "sssssss","cc","fewerwr" };
//	X10_20(a);
	X10_21();
	getchar();
	return 0;
}