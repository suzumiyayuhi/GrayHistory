#pragma once
//15_7
#include"Quote.h"
struct Limit_discount:public Quote
{
public:
	Limit_discount() = default;
	Limit_discount(const std::string &str, const std::size_t pri) :
		Quote(str, pri) {}
	double net_price(std::size_t n)const override {
		if (n <= 10) {
			return n*(1 - discount)*price;
		}
		else{
			return (n - 10)*price + 10 * (1 - discount)*price;
		}
	}
private:
	std::size_t limit = 10;
	double discount = 0.8;
};