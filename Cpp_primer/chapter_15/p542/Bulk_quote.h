#pragma once
#include"Disc_quote.h"
//15_15
struct Bulk_quote :public Disc_quote {
private:
public:
	Bulk_quote(const string &str, const double &pri, const size_t &sz,
		const double &dis) :Disc_quote(str, pri, sz, dis) {}
	  double net_prize(const size_t &n) const override;
};