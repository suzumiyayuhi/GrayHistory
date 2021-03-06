#pragma once
#include"Quote.h"
struct Bulk_quote :public Quote
{
public:
	using Quote::Quote;
	Bulk_quote() = default;
	Bulk_quote(const std::string &str, const double &pri, const std::size_t &mq,
		const double &dis) :Quote(str, pri), min_qty(mq), discount(dis){}
	Bulk_quote(const Bulk_quote &bq) :Quote(bq) {
		min_qty = bq.min_qty;
		discount = bq.discount;
	}
	//______________________________________-
	Bulk_quote* clone() const& { return new Bulk_quote(*this); }
	Bulk_quote* clone() && {return new Bulk_quote(std::move(*this)); }
	//___________________________________________
	Bulk_quote& operator=(const Bulk_quote &bq) {
		Quote::operator=(bq);
		min_qty = bq.min_qty;
		discount = bq.discount;
		return *this;
	}
	double net_price(std::size_t n)const override{
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