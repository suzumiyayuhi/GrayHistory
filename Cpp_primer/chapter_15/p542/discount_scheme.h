#pragma once
#include"Disc_quote.h"
//15_16
struct discount_scheme :public Disc_quote {
private:
public:
	discount_scheme(const string &str, const double &pri, const size_t &sz, const double &dis) :
		Disc_quote(str, pri, sz, dis) {}
	double net_prize(const size_t &n) const override{
		if (n <= quantity) {
			return n*(1-discount)*price;
		}
		else {
			return 10 * (1 - discount)*price + (n - 10)*price;
		}
	}
};