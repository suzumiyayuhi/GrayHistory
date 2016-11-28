#include<string>
#include<iostream>
#include<fstream>
using namespace std;
void X9_47_vol1(string a,string b) {
	string::size_type pos = 0;
	while ((pos=a.find_first_of(b,pos))!=string::npos)
	{
		cout << pos << " " << a[pos] << endl;
		++pos;
	}
}
void X9_47_vol2(string a, string b) {
	string::size_type pos = 0;
	while ((pos=a.find_first_not_of(b,pos))!=string::npos)
	{
		cout << pos << " " << a[pos] << endl;
		++pos;
	}
}
//9_48
//·µ»Ønpos
void X9_49(string a,string b) {
	fstream content(a);
	string temp, maxstr;
	int  maxsize = 0;
	while (content >> temp)
	{
		if (temp.find_first_of(b) != string::npos) {
			continue;
		}
		else
		{
			if (temp.size()>maxsize)
			{
				maxsize = temp.size();
				maxstr = temp;
			}
		}
	}
	cout << maxstr;
}
int main() {
	string a = { "ab2c3d7R4E6" };
	string b = { "1234567890" };
	string c = { "abcRe" };
	string d = { "bdfghjklpqty" };
	string e = { "word.txt" };
	X9_49(e, d);
	getchar();
	return 0;
}