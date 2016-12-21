#pragma once
//15_3
#include<iostream>
#include<string>
struct Quote
{
public:
	Quote() = default;
	Quote(std::string str, double pr) :bookNo(str), price(pr) {}
	void print_total(const Quote &q) {

	}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n)const {
		return n*price;
	}
	virtual ~Quote() = default;
	virtual double print_total(std::ostream &os, const Quote &q, const std::size_t &n) {
		double ret = q.net_price(n);
		os << "ISBN:" << q.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
		return ret;
	}
private:
	std::string bookNo;
protected:
	double price = 0.0;
};
