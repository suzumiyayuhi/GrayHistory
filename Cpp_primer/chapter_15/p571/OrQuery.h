#pragma once
#include"BinaryQuery.h"
class OrQuery :public BinaryQuery {
	friend Query operator| (const Query &, const Query &);
	OrQuery(const Query &lhs, const Query &rhs) :BinaryQuery(lhs, rhs, "|") {
		cout << "OrQuery(const Query&,const Query&)" << endl;
	}
};
inline Query operator|(const Query &l, const Query &r) {
	return shared_ptr<Query_base>(new OrQuery(l, r));
}