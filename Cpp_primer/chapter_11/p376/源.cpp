//11_1
//map关联容器，是关键字对值得容器，依靠关键字存放数据。
//vector是顺序容器，依靠空间顺序存放数据。

//11_2
//list：适合快速删除，插入数据，学生信息管理应用。
//vector：适合快速进行随机访问，电子书应用。
//deque：适合快速对首尾两段元素的访问，聊天应用。
//map：字典应用。
//set：检索应用。
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
void X11_3() {
	map<string, int> dic;
	string word;
	while (cin >> word)
	{
		++dic[word];
	}
	for (const auto &w : dic)
		cout << w.first << " " << w.second << endl ;
}
void X11_4() {
	map<string, int> dic;
	string word;
	while (cin >> word)
	{
		
		if (word.find_first_of(",.QWERTYUIOPASDFGHJKLZXCVBNM")!=string::npos)
		{
			++dic[word];
		}
	}
	for (const auto &w : dic)
		cout << w.first << " " << w.second << endl;
}

int main() {
	X11_4();
	getchar();
	return 0;
}