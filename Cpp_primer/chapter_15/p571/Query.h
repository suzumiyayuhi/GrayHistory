#pragma once
#include"Query_base.h"
#include"WordQuery.h"
#include<memory>
struct WordQuery;
//15_35
class Query {
	friend Query operator~ (const Query &);
	friend Query operator| (const Query &,const Query &);
	friend Query operator& (const Query &, const Query &);
public:
	Query(const string &str) :q(new WordQuery(str)){
		cout << "Query(const string &)" << endl;
	}
	string rep() const {
		cout<<"Query::rep()"<<endl;
		return q->rep();
	}
private:
	Query(shared_ptr<Query_base> query) :q(query) { cout << "Query(shared_ptr<Query_base>)" << endl; }
	shared_ptr<Query_base> q;
};
ostream& operator<<(ostream &os, const Query &query) {
	return os << query.rep();
}