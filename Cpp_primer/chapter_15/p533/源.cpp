//15_4
struct Base
{
	int a;
};
//class Derived:public Derived{...}; ����,�಻�ܼ̳�������
//class Derived:private Base{...};��ȷ
//class Derived:public Base;����,����������ð������������б�
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