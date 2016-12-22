#pragma once
#include"Query.h"
#include"Query_base.h"
class NotQuery :public Query_base {
	friend Query operator~ (const Query &q);
	NotQuery(const Query &q) :query(q) { cout << "NotQuery(const Query&)" << endl; }
	string rep() const{
		cout << "NotQuery::rep()" << endl;
		return "~(" + query.rep() + ")";
	}
	Query query;
};
inline Query operator~ (const Query &operand) {
	return shared_ptr<Query_base>(new NotQuery(operand));
}