#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Sales_data {
	friend struct hash<Sales_data>;
	friend bool operator==(const Sales_data &, const Sales_data&);
public:
	void print() {
		cout << book_no << " " << units_sold << " " << revenu << endl;
	}
	Sales_data(const string &a, const unsigned &b, const double& c) :book_no(a)
		, units_sold(b), revenu(c) {}
private:
	string book_no;
	unsigned units_sold;
	double revenu;
};

bool operator==(const Sales_data &a, const Sales_data &b) {
	return a.book_no == b.book_no;
}