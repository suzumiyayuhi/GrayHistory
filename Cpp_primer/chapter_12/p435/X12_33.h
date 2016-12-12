#pragma once
#include<string>
#include<memory>
#include<set>
#include<new>
#include<vector>
#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

struct TextQueryResult
{
public:
	friend void printResult(const TextQueryResult &temp);
	TextQueryResult(string a, shared_ptr<vector<string>> b, shared_ptr<set<vector<string>::size_type>> c)
		:Key(a), Text(b), lines(c) {}
	//12_33
	//定义新方法begin，end，getfile
	set<vector<string>::size_type>::iterator begin() { return lines->begin(); }
	set<vector<string>::size_type>::iterator end() { return lines->end(); }
	shared_ptr<vector<string>> get_file() { return Text; }
	//————————————————————————————————————————————————————
private:
	string Key;
	shared_ptr<vector<string>> Text;
	shared_ptr<set<vector<string>::size_type>> lines;
};

struct TextQuery
{
public:
	TextQuery() {}
	TextQuery(ifstream&);
	TextQueryResult query(string);
private:
	shared_ptr<vector<string>> Text;
	map<string, shared_ptr<set<vector<string>::size_type>>> result;
};
TextQuery::TextQuery(ifstream& is) :Text(new vector<string>) {	//要先给予初始值，否则报错无访问权限
	string line;
	while (getline(is, line))
	{
		stringstream strstream(line);
		Text->push_back(line);
		string word;
		vector<string>::size_type lineNO = Text->size() - 1;
		while (strstream >> word)
		{
			auto &info = result[word];
			if (!info)
			{
				info.reset(new set<vector<string>::size_type>);//分配新set
			}
			info->insert(lineNO);//插入当前行
		}
	}
}

TextQueryResult TextQuery::query(string key)
{
	auto location = result.find(key);
	shared_ptr < set<vector<string>::size_type>> NoData;	//原来加了static，改了之后似乎也没有发生什么问题，等之后解决
	NoData.reset(new set<vector<string>::size_type>);
	if (location == result.end())
	{
		return TextQueryResult(key, Text, NoData);
	}
	else
	{
		return TextQueryResult(key, Text, location->second);
	}
}
void printResult(const TextQueryResult &temp) {
	cout << "The key is:" << temp.Key << endl << endl;
	cout << "The key occurs " << temp.lines->size() << " times" << endl << endl;
	for (auto a : *temp.lines)
		cout << "line " << a + 1 << " " << *((temp.Text)->begin() + a) << endl;

}
