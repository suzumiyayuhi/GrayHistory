#include"iostream"
#include"string"
#include"vector"
using namespace std;
int man()
{
	vector <string>ivm(10, "ddd");
		for (auto a=ivm.cbegin(); a!= ivm.cend(); a++)
			cout << *a << "   ";
	getchar();
	return 0;
}