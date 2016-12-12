#include"iostream"
#include"string"
#include"vector"
using namespace std;

int min()
{
	string text = "prprpr lalala";
	for (auto a = text.begin(); !isblank(*a); a++)
	{
		*a = toupper(*a);
	}
	cout << text;
	getchar();
	return 0;
}