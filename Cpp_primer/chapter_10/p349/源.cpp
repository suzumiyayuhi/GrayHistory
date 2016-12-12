#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void X10_14() {
	auto lam = [](int a,int b) {return a + b; };
	cout << lam(1,4);
}
void X10_15(int a) {
	auto lam = [a](int b) {return a + b; };
	cout << lam(3);
}
void elimDups(vector<string> &a) {
	sort(a.begin(), a.end());
	auto uni = unique(a.begin(), a.end());
	a.erase(uni, a.end());
}
void X10_16(vector<string> &a, vector<string>::size_type sz) {
	elimDups(a);
	stable_sort(a.begin(), a.end(), []
		(const string &x,const string &y) 
			{return x.size() < y.size(); });
	auto iter = find_if(a.begin(), a.end(), [sz]
		(const string &a) 
			{return a.size() >= sz; });
	auto count = a.end() - iter;
	cout << count << endl;
	for_each(iter, a.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
struct sales_data
{
	string isbn;
};
void X10_17(vector<sales_data> &a) {
	sort(a.begin(), a.end(), [](sales_data x, sales_data y) {return x.isbn > y.isbn; });
}
void X10_18(vector<string> &a, vector<string>::size_type sz) {
	elimDups(a);
	auto iter = partition(a.begin(), a.end(), [sz]
		(const string &a)
			{return a.size() < sz; });
	auto count = a.end() - iter;
	cout << count << endl;
	for_each(iter, a.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
void X10_19(vector<string> &a, vector<string>::size_type sz) {
	elimDups(a);
	auto iter = stable_partition(a.begin(), a.end(), [sz]
	(const string &a)
	{return a.size() < sz; });
	auto count = a.end() - iter;
	cout << count << endl;
	for_each(iter, a.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}

int main() {
//	X10_14();
//	X10_15(2);
	vector<string> x = { "wer","ffg","ddddd","xc","rqwrtsf","sc" };
//	X10_16(x, 5);
	X10_19(x,5);
	getchar();
	return 0;
}