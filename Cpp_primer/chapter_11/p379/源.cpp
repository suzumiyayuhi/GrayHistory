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
	//vector<int>::iterator����
	//list<int>::iterator���Դ���������Ϊlist<int>iterator�����޷�ʹ��<=,>=�Ƚϣ����Բ���ִ��������ݵĲ�����
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
	multiset<Sales_data, compareType> bookstore(compareIsbn);	//��Ҫ�ٿ�һƪP221ҳ

}
int main() {
	X11_11();
	getchar();
	return 0;
}