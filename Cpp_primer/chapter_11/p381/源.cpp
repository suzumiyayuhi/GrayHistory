#include<utility>
#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;
void X11_12(string str,int order) {
	if (!str.empty() && !order) {
		vector<pair<string, int>> saving;
		saving.push_back(make_pair(str, order));
	}
}
void X11_13() {
	pair<string, int> x = { "str",2 };
	pair<string, int> x1("str", 4);
	//原先的更好理解吧= =
}
void X11_14() {
	map<string, vector<string>> names;
	string name;
	while (cin >> name)
	{
		names["Kirisame"].push_back(name);
	}
	for (auto x : names) {
		cout << x.first << " ";
		for (auto y : x.second)
			cout << y << endl;
	}
	vector < pair<string, string>> BirthName;
}
int main() {
	getchar();
	return 0;
}