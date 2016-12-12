#include"iostream"
#include"string"
#include"vector"
using namespace std;
int min()
{
	vector <int>mark(10, 0);
	int a;
	for (auto b = mark.begin(); cin >> a; b = mark.begin())
	{
		if (a > 100)
			break;
		a = a / 10;
		b += a;
		(*b)++;
	}
	getchar();
	return 0;
}