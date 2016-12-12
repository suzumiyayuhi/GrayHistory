#include<string>
#include<iostream>
#include<memory>
using namespace std;
//12_23
void x12_23(string &a,string &b) {
	a.append(b);
	char *ch = new char[a.size()];
	for (int i = 0; i <= a.size(); ++i)
	{
		ch[i] = a[i];
	}
	cout << ch;
}
//_____________________________________________________________________________________________
//12_24
void x12_24() {
	string a;
	cin >> a;
	char *b = new char[10];
	if (a.size() > 10)
	{
		throw out_of_range("size too big");//过长时抛出异常
	}
	for (int i = 0; i <= a.size(); ++i)
	{
		b[i] = a[i]; 
	}
	cout << b;
}
//____________________________________________________________________________________________
//12_25
void x12_25() {
	int *pa = new int[10];
	delete[] pa;
}
int main() {
	string a("sd");
	string b("ff");
	x12_24();
	cin >> a;
	getchar();
	return 0;
}