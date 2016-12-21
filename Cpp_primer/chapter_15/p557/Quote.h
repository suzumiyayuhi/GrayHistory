#pragma once
#include<iostream>
#include<string>
struct Quote
{
public:
	Quote() = default;
	Quote(std::string str, double pr) :bookNo(str), price(pr) {
		std::cout << "Quote constructor" << std::endl;
	}
	void print_total(const Quote &q) {

	}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n)const {
		return n*price;
	}
	//15_26
	Quote(const Quote &q) {
		std::cout << "Quote (const Quote &q)" << std::endl;
		bookNo = q.bookNo;
		price = q.price;
	}
	Quote& operator=(const Quote &q) {
		std::cout << "Quote& operator=(const Quote &q)" << std::endl;
		bookNo = q.bookNo;
		price = q.price;
		return *this;
	}
	//！！！！！！！！！！！！！！！！！！！！！！
	virtual ~Quote() = default;
	virtual double print_total(std::ostream &os, const Quote &q, const std::size_t &n) {
		double ret = q.net_price(n);
		os << "ISBN:" << q.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
		return ret;
	}
	virtual void debug() {
		std::cout << "bookNo:" << bookNo << " " << "price:" << price << std::endl;
	}
private:
	std::string bookNo;
protected:
	double price = 0.0;
};
