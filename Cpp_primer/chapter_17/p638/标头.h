#pragma once
#include<vector>
#include<memory>
#include<map>
#include<set>
#include<fstream>
#include<string>
#include<strstream>
#include<sstream>
#include<tuple>
#include<iostream>
using namespace std;

struct TextQuery
{
public:
	TextQuery() {}
	TextQuery(ifstream&);
	tuple<string, shared_ptr<vector<string>>, shared_ptr<set<size_t>>> query(string);
private:
	shared_ptr<vector<string>> Text;
	map<string, shared_ptr<set<vector<string>::size_type>>> result;
};
TextQuery::TextQuery(ifstream& is) :Text(new vector<string>) {
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

tuple<string, shared_ptr<vector<string>>, shared_ptr<set<size_t>>>TextQuery::query(string key)
{
	auto location = result.find(key);
	static shared_ptr < set<vector<string>::size_type>> NoData;
	NoData.reset(new set<vector<string>::size_type>);
	if (location == result.end())
	{
		return tuple<string, shared_ptr<vector<string>>, shared_ptr<set<size_t>>>(key, Text, NoData);
	}
	else
	{
		return tuple<string, shared_ptr<vector<string>>, shared_ptr<set<size_t>>>(key, Text, location->second);
	}
}
void printResult(const tuple<string, shared_ptr<vector<string>>, shared_ptr<set<size_t>>> &temp) {
	cout << "The key is:" << get<0>(temp) << endl << endl;
	cout << "The key occurs " << get<1>(temp)->size() << " times" << endl << endl;
	for (auto a : *get<2>(temp))
		cout << "line " << a + 1 << " " << *((get<1>(temp))->begin() + a) << endl;

}
