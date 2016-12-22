#pragma once
#include<iostream>
#include<string>
struct Quote
{
public:
	Quote() = default;
	Quote(std::string str, double pr) :bookNo(str), price(pr) {}
	std::string isbn() const { return bookNo; }
	//____________________________________________
	virtual Quote* clone() const& { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); }
	//__________________________________________________
	virtual double net_price(std::size_t n)const {
		return n*price;
	}
	Quote(const Quote &q) {
		bookNo = q.bookNo;
		price = q.price;
	}
	Quote& operator=(const Quote &q) {
		bookNo = q.bookNo;
		price = q.price;
		return *this;
	}
	virtual ~Quote() = default;
	virtual void debug() {
		std::cout << "bookNo:" << bookNo << " " << "price:" << price << std::endl;
	}
private:
	std::string bookNo;
protected:
	double price = 0.0;
};
