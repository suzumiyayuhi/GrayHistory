#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void X10_11(vector<string> &a) {
	stable_sort(a.begin(), a.end(), isShorter);
	for (auto x : a)
		cout << x << endl;
}
struct Sales_data
{
	string isbn;
};

bool compareIsbn(Sales_data s1, Sales_data s2) {
	return s1.isbn < s2.isbn;
}
void X10_12(vector<Sales_data> &a) {
	stable_sort(a.begin(), a.end(), compareIsbn);
} 
bool X10_13(string a) {
	return a.size() >= 5;
}
void X10_13_sort(vector<string> &words) {
	auto last_true = partition(words.begin(), words.end(), X10_13);
	auto wordsbegin = words.begin();
	while (wordsbegin != last_true) {
		cout << *wordsbegin;
		++wordsbegin;
	}
}

int main() {
	vector<string> a = { "ab","mkpd","dsw","xcvbr" };
//	X10_11(a);
	X10_13_sort(a);
	getchar();
	return 0;
}