#include<string>
#include<iostream>
using namespace std;
struct person
{
	person() = default;
	person(istream &);
	string ReturnName() const { return name; }
	string ReturnLocation() const { return location; }
	string name;
	string location;
};

istream &readin(istream &is, person a) {
	cout << "key into the name:";
	is >> a.name;
	cout << "key into the location:";
	is >> a.location;
	return is;
}

person::person(istream &is) {
	readin(is, *this);
}

ostream &print(ostream &os, const person a) {
	os << "name of the person:" << a.name << endl;
	os << "location of the person:" << a.location << endl;
	return os;
}
int main() {
	person x;
	readin(cin, x);
	print(cout, x);
	getchar();
	return 0;
}