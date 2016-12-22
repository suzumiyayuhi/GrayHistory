#pragma once
#include"Query.h"
#include"Query_base.h"
class WordQuery :public Query_base {
	friend class Query;
	WordQuery(const string &str) :query_word(str) { 
		cout << "WordQuery(const string &str)" << endl;
	}
	string rep() const{
		cout << "WordQuery::rep()" << endl;
		return query_word;
	}
	string query_word;
};