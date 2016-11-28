#include<forward_list>
#include<string>
#include<iostream>
using namespace std;
void X9_27(forward_list<int> a) {
	auto prev = a.before_begin();
	auto curr = a.begin();
	while (curr!=a.end())
	{
		if (*curr%2==0)
		{
			curr = a.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
	for (auto gg : a)
		cout << gg;
}
void X9_28(forward_list<string> &a, string aa, string bb) {
	bool flag = false;
	auto xx = a.begin();
	auto yy = a.before_begin();
	while (xx != a.end())
	{
		if (*xx==aa)
		{
			xx=a.insert_after(xx, bb);
			flag = true;
			break;
		}
		yy = xx;
		++xx;
	}
	if (!flag)
	{
		a.insert_after(yy, bb);
	}
}
int main() {
	forward_list<string> xx = { "sdd","wwww" };
	X9_28(xx,"sddd","xxxx");
	for (auto a : xx)
		cout << a;
	getchar();
	return 0;
}