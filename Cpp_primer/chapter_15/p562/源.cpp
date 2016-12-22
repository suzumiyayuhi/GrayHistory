#include"Basket.h"
using namespace std;

int main() {
	Bulk_quote a("a", 2.0, 5, 0.5);
	Bulk_quote b("b", 4.2, 5, 0.5);
	Basket bas;
	//这下面有点蠢-_-||
	bas.add_item(make_shared<Bulk_quote>(a));
	bas.add_item(make_shared<Bulk_quote>(a));
	bas.add_item(make_shared<Bulk_quote>(a));
	bas.add_item(make_shared<Bulk_quote>(a));
	bas.add_item(make_shared<Bulk_quote>(a));
	bas.add_item(a);
	bas.add_item(make_shared<Bulk_quote>(b));
	bas.total_receipt(cout);
	//___________________________________________
	getchar();
}