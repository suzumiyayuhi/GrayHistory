//11_5
//map是关键字对值的容器，set为存储关键字的容器。
//字典应用应使用map，在set里存储关键字作索引。

//11_6
//map是关联容器，存储关联字，且不能有重复元素。
//list是链表，顺序容器，可存有重复数据
#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void X11_7() {
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
}
void X11_8() {
	//vector适合经常插入和修改数据。
	//set无论何时，一直都不会有重复的数据存在。
	vector<string> exclude;
	string word;
	while (cin>>word)
	{
		for (auto X : exclude) {
			if (X.find(word))
				break;
			else
			{
				exclude.push_back(word);
			}
		}
	}
}
int main()
{
	X11_7();
	getchar();
	return 0;
}