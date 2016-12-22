#pragma once
#include"Query.h"
#include"Query_base.h"
class BinaryQuery :public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, const string &str) :
		lhs(l), rhs(r), operaName(str) {
		cout << "BinaryQuery(const Query&,const Query&,const string)" << endl;
	}
	string rep() const {
		cout << "BinaryQuery::rep()" << endl;
		return lhs.rep() + " " + operaName + " " + rhs.rep();
	}
	Query lhs, rhs;
	string operaName;
};