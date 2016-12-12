//11_37
//无需容器不关心关键字的排序
//不对其进行维护，以提升性能
//有序容器则会一直对数据元素的序列进行维护
//使得元素排列总是有序的

#include<map>
#include<unordered_map>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//以下为11_38
//以下为单词计数程序
void CountWord(unordered_map<string,int> &theMap) {
	string word;
	while (cin >> word)
	{
		++theMap[word];
	}
	for (auto X : theMap)
		cout << X.first << " " << X.second << endl;
}
//以上为单词计数程序

//以下为单词转换程序
unordered_map<string, string> BuildMap(ifstream &RuleStream) {
	unordered_map<string, string> Rule;
	string oldstr, newstr;
	while (RuleStream>>oldstr)
	{
		getline(RuleStream, newstr);

		Rule.insert({ oldstr,newstr });
	}
	return Rule;
}
pair<string,bool> transfrom(unordered_map<string, string> &Rule, string &thisStr) {
	auto temp = Rule.find(thisStr);
	if (temp!=Rule.end())
	{
		return make_pair(temp->second, true);
	}
	else
	{
		return make_pair(thisStr, false);
	}
}
void MainTransfrom(ifstream &RuleStream,ifstream &FileStream) {
	auto Rule = BuildMap(RuleStream);
	string line;
	while (FileStream >> line)
	{
		auto temp = transfrom(Rule, line);
				if (temp.second==true)
				{
					cout << temp.first<<" ";
				}
				else
				{
					cout << line;
				}
	}
}
//以上为单词转换程序
int main() {
	ifstream a("1.txt");
	ifstream b("2.txt");
	MainTransfrom(a, b);
	getchar();
	return 0;
}