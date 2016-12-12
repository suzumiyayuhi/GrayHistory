#pragma once
#include <string>
#include <iostream>
class Sales_data {
public:
	friend std::istream& operator >> (std::istream&, Sales_data&);       // input
	friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output
	friend Sales_data operator+(const Sales_data&, const Sales_data&); // addition
	Sales_data(const std::string& s, unsigned n, double p)
		: bookNo(s), units_sold(n), revenue(n * p)
	{
	}
	Sales_data() : Sales_data("", 0, 0.0f) {}
	Sales_data(const std::string& s) : Sales_data(s, 0, 0.0f) {}
	Sales_data(std::istream& is);
	Sales_data& operator+=(const Sales_data&); // compound-assignment
	std::string isbn() const { return bookNo; }
	//14_22
	Sales_data& operator=(const string &str) {
		bookNo = str;
		return *this;
	}
private:
	inline double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
std::istream& operator >> (std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}