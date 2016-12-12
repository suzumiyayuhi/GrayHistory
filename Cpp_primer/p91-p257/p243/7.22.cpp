
#include<string>
#include<iostream>
using namespace std;
struct person
{
	friend istream &readin(istream&, person&);
	friend ostream &printout(ostream&, person&);
public:
	person() = default;
	person(istream &);
	string ReturnName() const { return name; }
	string ReturnLocation() const { return location; }
private:
	string name;
	string location;
};


person::person(istream &is) {
	readin(is, *this);
}

int main() {
	person x(cin);
	printout(cout, x);
	getchar();
	return 0;
}

istream & readin(istream &is, person &a)
{
	// TODO: insert return statement here
	cout << "key into the name:";
	is >> a.name;
	cout << "key into the location:";
	is >> a.location;
	return is;
}

ostream & printout(ostream &os, person &a)
{
	// TODO: insert return statement here
	os << "name of the person:" << a.name << endl;
	os << "location of the person:" << a.location << endl;
	return os;
}
