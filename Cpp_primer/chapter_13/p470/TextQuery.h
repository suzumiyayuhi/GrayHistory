#pragma once
#include"StrVec.h"
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include<sstream>
#include<algorithm>
using namespace std;
//13_42
struct TextQueryResult
{
public:
	friend void printResult(const TextQueryResult &temp);
	TextQueryResult(string a, shared_ptr<StrVec> b, shared_ptr<set<size_t>> c)
		:Key(a), Text(b), lines(c) {}
private:
	string Key;
	shared_ptr<StrVec> Text;
	shared_ptr<set<size_t>> lines;
};

struct TextQuery
{
public:
	TextQuery() {}
	TextQuery(ifstream&);
	TextQueryResult query(string);
private:
	shared_ptr<StrVec> Text;
	map<string, shared_ptr<set<size_t>>> result;
};
TextQuery::TextQuery(ifstream& is) :Text(new StrVec) {	//要先给予初始值，否则报错无访问权限
	string line;
	while (getline(is, line))
	{
		stringstream strstream(line);
		Text->push_back(line);
		string word;
		size_t lineNO = Text->size() - 1;
		while (strstream >> word)
		{
			auto &info = result[word];
			if (!info)
			{
				info.reset(new set<size_t>);//分配新set
			}
			info->insert(lineNO);//插入当前行
		}
	}
}

TextQueryResult TextQuery::query(string key)
{
	auto location = result.find(key);
	static shared_ptr < set<size_t>> NoData;
	NoData.reset(new set<size_t>);
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


/*
class QueryResult;
class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<StrVec> input;
	std::map<std::string, std::shared_ptr<std::set<size_t>>> result;
};

class QueryResult {
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);

public:
	QueryResult(const std::string& s, std::shared_ptr<std::set<size_t>> set,
		std::shared_ptr<StrVec> v)
		: word(s), nos(set), input(v)
	{
	}

private:
	std::string word;
	std::shared_ptr<std::set<size_t>> nos;
	std::shared_ptr<StrVec> input;
};

std::ostream& print(std::ostream&, const QueryResult&);


TextQuery::TextQuery(std::ifstream& ifs) : input(new StrVec)
{
	size_t lineNo = 0;
	for (string line; std::getline(ifs, line); ++lineNo) {
		input->push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear()) {
			// avoid read a word followed by punctuation(such as: word, )
			std::remove_copy_if(text.begin(), text.end(),
				back_inserter(word), ispunct);
			// use reference avoid count of shared_ptr add.
			auto& nos = result[word];
			if (!nos) nos.reset(new std::set<size_t>);
			nos->insert(lineNo);
		}
	}
}

QueryResult TextQuery::query(const string& str) const
{
	// use static just allocate once.
	static std::shared_ptr<std::set<size_t>> nodate(new std::set<size_t>);
	auto found = result.find(str);
	if (found == result.end())
		return QueryResult(str, nodate, input);
	else
		return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream& out, const QueryResult& qr)
{
	out << qr.word << " occurs " << qr.nos->size()
		<< (qr.nos->size() > 1 ? " times" : " time") << std::endl;
	for (auto i : *qr.nos)
		out << "\t(line " << i + 1 << ") " << qr.input->at(i) << std::endl;
	return out;
}*/