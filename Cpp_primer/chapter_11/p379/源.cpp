#include<string>
#include<map>
#include<vector>
#include<list>
#include<iostream>
#include<set>
using namespace std;
void X11_9() {
	list<int> line;
	map<string, list<int>> words;
}
void X11_10() {
	//vector<int>::iterator可行
	//list<int>::iterator可以创建，但因为list<int>iterator本身无法使用<=,>=比较，所以不能执行添加数据的操作。
	map<vector<int>::iterator, int> xx;
	map<list<int>::iterator, int> yy;
}
struct Sales_data
{
	string isbn;
};
bool compareIsbn(Sales_data a, Sales_data b) {
	return a.isbn > b.isbn;
}
void X11_11() {
	using compareType = bool(*)(Sales_data, Sales_data);
	multiset<Sales_data, compareType> bookstore(compareIsbn);	//需要再看一篇P221页

}
int main() {
	X11_11();
	getchar();
	return 0;
}