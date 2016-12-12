//11_27
//count查找元素数量
//find查找元素是否存在

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
//upper_bound与lower_bound会返回同一个不影响插入的迭代器

//11_30
//对pair类型的pos第一个成员迭代器进行解引用，并返回该map迭代器解引用后的值

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