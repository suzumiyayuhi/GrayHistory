#pragma once
//15_5
#include"Quote.h"
struct Bulk_quote :public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &str, const std::size_t &pri, const std::size_t &mq,
		const double &dis) :Quote(str, pri), min_qty(mq), discount(dis) {}
	double net_price(std::size_t n)const override {
		if (n >= min_qty) {
			return n*price*(1 - discount);
		}
		else {
			return n*price;
		}
	}
	void debug() override {
		Quote::debug();
		std::cout << "min_qty:" << min_qty << "discount:" << discount << std::endl;
	}
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};