//17_31
//每步循环都将会生成相同的值

//17_32
//会导致编译出错

#include<iostream>
#include<cmath>
#include<random>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<iterator>
using namespace std;

multimap<string, string> BuildRule(ifstream &RuleFile) {
	multimap<string, string> Rule;
	string newstr, oldstr;
	while (RuleFile >> oldstr)
	{
		getline(RuleFile, newstr);
		newstr.substr(1);
		Rule.insert({ oldstr, newstr });
	}
	return Rule;
}
pair<string, bool >transfrom(const multimap<string, string> &rule, const string &oldstr) {
	//17_33
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0,rule.count(oldstr));
	auto target = rule.find(oldstr);
	for (int tem = u(e); tem != 0; --tem) {
		++target;
	}
	//__________________________________
	if (target != rule.end())
	{
		return make_pair(target->second , true);
	}
	else
	{
		return make_pair(oldstr, false);
	}
}
void MainTrans(ifstream &RuleFile, ifstream &textFile) {
	auto Rule = BuildRule(RuleFile);
	string Line;
	while (getline(textFile, Line))
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

int main() {
	ifstream a("1.txt");
	ifstream b("2.txt");
	MainTrans(a, b);
	cout << endl << endl;
	getchar();
	return 0;
}