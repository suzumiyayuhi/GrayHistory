#include"Sales_data.h"
using namespace std;
//14_21
//Ğ§ÂÊµÄ½µµÍ
Sales_data& Sales_data::operator+=(const Sales_data &data) {
	*this = *this + data;
	return *this;
}
Sales_data operator+( const Sales_data &a,const Sales_data &b) {
	unsigned units_s = a.units_sold + b.units_sold;
	double rev = a.revenue + b.revenue;
	return Sales_data(a.bookNo, units_s, rev);
}
