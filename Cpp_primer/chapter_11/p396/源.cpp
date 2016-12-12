//11_37
//�������������Ĺؼ��ֵ�����
//���������ά��������������
//�����������һֱ������Ԫ�ص����н���ά��
//ʹ��Ԫ���������������

#include<map>
#include<unordered_map>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//����Ϊ11_38
//����Ϊ���ʼ�������
void CountWord(unordered_map<string,int> &theMap) {
	string word;
	while (cin >> word)
	{
		++theMap[word];
	}
	for (auto X : theMap)
		cout << X.first << " " << X.second << endl;
}
//����Ϊ���ʼ�������

//����Ϊ����ת������
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
//����Ϊ����ת������
int main() {
	ifstream a("1.txt");
	ifstream b("2.txt");
	MainTransfrom(a, b);
	getchar();
	return 0;
}