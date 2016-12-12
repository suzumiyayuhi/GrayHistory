#include"iostream"
#include"string"
#include"vector"
using namespace std;
int main()
{
	vector <int>ivm(10, 10);
	for (auto a = ivm.begin(); a!=ivm.cend(); a++)
	{
		*a = (*a) * 10;
		cout << *a<<"  ";
	}

	getchar();
}