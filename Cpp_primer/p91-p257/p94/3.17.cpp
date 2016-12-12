#include"iostream"
#include"string"
#include"vector"
#include"cctype"
using namespace std;
int main()
{
	int temp = 0;
	vector <string>kha(10);
	for (string i : kha)
	{
		cin >> i;
		for (char &b : i) {
			b=toupper(b);
		}
		kha[temp] = i;
		temp++;
	}
	cout << endl;
	return 0;
}