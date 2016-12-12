//11_15
//pair<int,vector<int>>
//int
//vector<int>

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;
void X11_16() {
	map<int, string> xx;
	auto iter = xx.begin();
	iter->second = "dd";
}
void X11_17() {
	vector<string> v = { "ll" };
	multiset<string> c = { "pp" };
	copy(v.begin(), v.end(), inserter(c,c.end()));
//	copy(v.begin(), v.end(), back_inserter(c));  multiset没有push_back成员方法
	copy(c.begin(), c.end(), inserter(v, v.end()));
	copy(c.begin(), c.end(), back_inserter(v));
}
void X11_18() {
	map<const string, size_t> word_count;
	map<const string, size_t>::iterator map_it = word_count.begin();
}
struct Sales_data
{
	string isbn;
};
bool compareIsbn(const Sales_data a, const Sales_data b) {
	return a.isbn < b.isbn;
}
void X11_19() {
	multiset<Sales_data, bool(*)(const Sales_data, const Sales_data)> bookstore(compareIsbn);
	Sales_data a, b;
	a.isbn = "ee";
	b.isbn = "ff";
	bookstore.insert(a);
	bookstore.insert(b);
	multiset<Sales_data>::iterator xx = bookstore.begin();
}
int main() {
	X11_19();
	getchar();
	return 0;
}