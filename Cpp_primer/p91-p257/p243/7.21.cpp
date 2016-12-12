/*
#include<iostream>
#include<string>
using namespace std;

struct  Sales_data
{
	friend istream &readin(istream&, Sales_data&);
	friend ostream &printout(ostream&, Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s) {}
	Sales_data(const string &s, unsigned &t, double &r) :
		bookNo(s), units_sold(t), revenue(t*r) {}
	Sales_data(istream &is) {
		readin(is, *this);
	}
	string isbn() const {
		return bookNo;
	}
	Sales_data& combine(const Sales_data &cnm);
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

istream &readin(istream &is, Sales_data &x) {
	double price = 0;
	cout << "press into bookNo:";
	is >> x.bookNo;
	cout << "press into units_sold:";
	is >> x.units_sold;
	cout << "price:";
	is >> price;
	x.revenue = price*x.units_sold;
	return is;
}

Sales_data &Sales_data::combine(const Sales_data &cnm) {
	units_sold += cnm.units_sold;
	revenue += cnm.revenue;
	return *this;
}

ostream &printout(ostream &os, Sales_data &x) {
	os << "bookNo:" << x.bookNo << endl
		<< "units_sold:" << x.units_sold << endl
		<< "revenue:" << x.revenue << endl;
	return os;
}

int main() {
	unsigned q = 2;
	double p = 2.0;
	Sales_data a(cin);
	Sales_data b("sdfq");
	Sales_data c("sdfe", q, p);
	printout(cout, a);
	printout(cout, b);
	printout(cout, c);
	getchar();
	return 0;
}
*/