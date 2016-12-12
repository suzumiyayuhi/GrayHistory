//����Ϊ11_33
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
//����Ϊ11_33

//X11_34
//�����Ϊ����һ�������ڵĹؼ��ֵ�Ԫ��
//ʹ����ﲻ��Ԥ������Ч��

//11_35
//û��;������䣬�����������(����)
//��ʹ��insert����map���Ѵ��ڸùؼ��֣�����¹ؼ��ֵ�ֵ
//��ʹ���±꣬���ؼ��ֲ����ڣ��ᴴ���µĹؼ��֣�����ֵΪ0

//11_36
//����ı��йؼ����滻Ϊ���ַ�

int main() {
	ifstream a("1.txt");
	ifstream b("2.txt");
	MainTrans(a, b);
	getchar();
	return 0;
}