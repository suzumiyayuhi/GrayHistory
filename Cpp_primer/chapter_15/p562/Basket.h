#pragma once
#include"Bulk_quote.h"
#include<set>
#include<memory>
using namespace std;
double print_total(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() << " # sold: " << n << " total due:" <<
		ret << endl;
	return ret;
}
//15_30
struct Basket {
public:
	void add_item(const shared_ptr<Quote> &ptr) {
		ms.insert(ptr);
	}
	//_______________________________________________
	void add_item(const Quote& sale) {
		ms.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale) {
		ms.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
	//_______________________________________________
	double total_receipt(ostream &os) const;
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare)*> ms{ compare };
};

double Basket::total_receipt(ostream &os) const {
	double sum = 0.0;
	for (auto iter = ms.cbegin();iter != ms.cend();iter= ms.upper_bound(*iter)) {
		sum += print_total(cout, **iter, ms.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}
//______________________________________________________________