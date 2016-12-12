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
void read(Sales_data &a) {
	cout << "bookNo:";cin >> a.bookNo;
	cout << endl;
	cout << "units_sold"; cin >> a.units_sold; 
	cout << endl;
	cout << "revenue"; cin >> a.revenue; 
	cout << endl;
}
int main() {
	Sales_data ranse;
	read(ranse);
	cout<<ranse.isbn();
	cout << ranse.combine(ranse).bookNo;
	getchar();
}*/