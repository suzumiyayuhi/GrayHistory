//11_27
//count����Ԫ������
//find����Ԫ���Ƿ����

#include<map>
#include<iostream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;

void X11_28() {
	map<string, vector<int>> x;
	auto a = x.find("dd");
}

//11_29
//upper_bound��lower_bound�᷵��ͬһ����Ӱ�����ĵ�����

//11_30
//��pair���͵�pos��һ����Ա���������н����ã������ظ�map�����������ú��ֵ

void X11_31() {
	multimap<string, string> x;
	x.insert({ "hhhh", "llll" });
	auto d = x.find("hhhh");
	x.erase(d);
	if (x.find("hhhh")==x.end())
	{
		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxx";
	}
}
void X11_32() {
	multimap<string, string> x;
	x.insert({ "hhhh", "llll" });
	auto d = x.find("hhhh");
	auto begin = x.begin();
	while (begin!=x.end())
	{
		cout << begin->first << " " << begin->second;
		++begin;
	}
}
int main() {
	X11_32();
	getchar();
	return 0;
}