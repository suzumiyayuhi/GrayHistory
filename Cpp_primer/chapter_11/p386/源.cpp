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
}//��γ���������

//11_21
//�ӱ�׼����������word�����һ�β���ؼ���word��ֵΪ1���˺����ֵ

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