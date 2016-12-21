#include"Quote.h"
#include"Bulk_quote.h"
int main() {
	Quote a("d",1.0);
	Bulk_quote b("b",2.0,3,0.4);

	a = b;
	Quote c(b);
	getchar();
}