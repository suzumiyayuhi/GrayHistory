#pragma once
#include"Quote.h"
using namespace std;
//15_15
struct Disc_quote :public Quote {
protected:
	size_t quantity = 0;
	double discount = 0.0;
public:
	Disc_quote() = default;
	Disc_quote(const string& str, const double &pri,
		const size_t &sz, const double &dis) :Quote(str, pri), quantity(sz), discount(dis){}
	virtual double net_prize(const size_t&)const = 0;
};