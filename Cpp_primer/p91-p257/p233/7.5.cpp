#include<string>
using namespace std;
struct person
{
	string ReturnName() const { return name; }
	string ReturnLocation() const { return location; }
	string name;
	string location;
};