#include<list>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main() {
	int ia[] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> x{ 1,2,3,4,5,6,7,8,9 };
	list<int> y{ 1,2,3,4,5,6,7,8,9 };
	auto bbb = x.begin();
	auto ccc = y.begin();
	while (bbb != x.end())
	{
		if (*bbb % 2 == 0)
		{
			bbb = x.erase(bbb);
		}
		else
		{
			++bbb;
		}
	}

	while (ccc != y.end())
	{
		if (*ccc % 2 != 0)
		{
			ccc = y.erase(ccc);
		}
		else
		{
			++ccc;
		}
	}

	for (auto dd : x)
		cout << dd;
	cout << endl;
	for (auto dd : y)
		cout << dd;
	getchar();
}