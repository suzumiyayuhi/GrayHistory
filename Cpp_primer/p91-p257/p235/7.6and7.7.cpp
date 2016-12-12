/*#include<iostream>
#include<string>
using namespace std;

struct  Sales_data
{
	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data &cnm);
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


Sales_data& Sales_data::combine(const Sales_data &cnm) {
	units_sold += cnm.units_sold;
	revenue += cnm.revenue;
	return *this;
}


istream &readin(istream &is, Sales_data &x) {
	double price = 0;
	cout << "press into bookNo";
	is >> x.bookNo;
	cout << "press into units_sold";
	is >> x.units_sold;
	cout << "price";
	is >> price;
	x.revenue = price*x.units_sold;
	return is;
}

ostream &printout(ostream &os,const Sales_data &x) {
	os << "bookNo:" << x.bookNo << endl 
		<< "units_sold:" << x.units_sold << endl 
		<< "revenue" << x.revenue << endl;
	return os;
}

int main() {
	Sales_data ranse;
	readin(cin, ranse);
	printout(cout, ranse);
	getchar();
	return 0;
}*/