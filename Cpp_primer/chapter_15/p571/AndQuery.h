#pragma once
#include"BinaryQuery.h"
class AndQuery :public BinaryQuery {
	friend Query operator& (const Query &, const Query &);
	AndQuery(const Query &l, const Query &r) :BinaryQuery(l, r, "&") {
		cout << "AndQuery(const Query&,const Query &,const string &)" << endl;
	}
};
inline Query operator& (const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}