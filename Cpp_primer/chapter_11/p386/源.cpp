#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
void X11_20() {
	map<string, int> words_count;
	string word;
	while (cin >> word)
	{
		auto temp = words_count.insert({ word,1 });
		if (temp.second != 1) {
			++temp.second;
		}
	}
}//这段程序更好理解

//11_21
//从标准输入流读入word，插第一次插入关键字word，值为1，此后递增值

void X11_22(vector<int> a) {
	map<string, vector<int>> x;
	pair<map<string,vector<int>>::iterator,bool> we = x.insert({"word",a});
}
void X11_23() {
	multimap<string, string> names;
	string firstname;
	string lastname;
	while (cin >> firstname >> lastname)
	{
		names.insert({ firstname,lastname });
	}
}
int main() {
	vector<int> a = { 1,23,4 };
	X11_22(a);
	getchar();
	return 0;
}