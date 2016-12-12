//以下为11_33
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
using namespace std;
map<string, string> BuildRule(ifstream &RuleFile) {
	map<string, string> Rule;
	string newstr, oldstr;
	while (RuleFile >> newstr)
	{
		getline(RuleFile, oldstr);
		oldstr.substr(1);
		Rule.insert({ newstr, oldstr });
	}
	return Rule;
}
pair<string, bool >transfrom (const map<string, string> &rule, const string &oldstr) {
	auto target = rule.find(oldstr);
	if (target != rule.end())
	{
		return make_pair(target->second,true);
	}
	else
	{
		return make_pair(oldstr,false);
	}
}
void MainTrans(ifstream &RuleFile, ifstream &textFile) {
	auto Rule = BuildRule(RuleFile);
	string Line;
	while (getline(textFile,Line))
	{
		istringstream stream(Line);
		string word;
		
		while (stream >> word)
		{
			auto tempword = transfrom(Rule, word);
			if (tempword.second == true)
			{
				cout << tempword.first;
			}
			else
			{
				cout << " " << word;
				
			}
		}
	}
}
//以上为11_33

//X11_34
//程序会为创建一个不存在的关键字的元素
//使程序达不到预期运行效果

//11_35
//没有;结束语句，产生编译错误(大雾)
//若使用insert，且map中已存在该关键字，则更新关键字的值
//若使用下标，若关键字不存在，会创建新的关键字，并且值为0

//11_36
//会吧文本中关键字替换为空字符

int main() {
	ifstream a("1.txt");
	ifstream b("2.txt");
	MainTrans(a, b);
	getchar();
	return 0;
}