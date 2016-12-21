#pragma once
#include"Quote.h"
struct Bulk_quote :public Quote
{
public:
	//15_27
	using Quote::Quote;
	//___________________________________________________________
	Bulk_quote() = default;
	Bulk_quote(const std::string &str, const double &pri, const std::size_t &mq,
		const double &dis) :Quote(str, pri), min_qty(mq), discount(dis)
	{
		std::cout << "Bulk_quote constructor" << std::endl;
	}
	Bulk_quote(const Bulk_quote &bq) :Quote(bq) {
		min_qty = bq.min_qty;
		discount = bq.discount;
		std::cout << "Bulk_quote(const Bulk_quote &bq):Quote(bq)" << std::endl;
	}
	Bulk_quote& operator=(const Bulk_quote &bq) {
		Quote::operator=(bq);
		min_qty = bq.min_qty;
		discount = bq.discount;
		std::cout << "Bulk_quote& operator=(const Bulk_quote &bq)" << std::endl;
		return *this;
	}
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