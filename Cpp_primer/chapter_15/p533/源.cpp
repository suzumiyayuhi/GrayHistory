//15_4
struct Base
{
	int a;
};
//class Derived:public Derived{...}; 错误,类不能继承他本身
//class Derived:private Base{...};正确
//class Derived:public Base;错误,类的声明不该包括他的派生列表
//____________________________________________________________
#include"Bulk_quote.h"
int main() {
	//15_6
	Quote a("aa", 2);
	Bulk_quote b("bb", 2, 3, 1);
	a.print_total(std::cout, a, 2);
	b.print_total(std::cout, b, 2);
	//_____________________________________________
	getchar();
}