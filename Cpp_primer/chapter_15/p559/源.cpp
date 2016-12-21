#include"Bulk_quote.h"
#include<vector>
#include<memory>
int main() {
	//15_28
	std::vector<Quote> vec;
	Bulk_quote a("a", 2.0, 5, 0.5);
	Bulk_quote b("b", 4.0, 5, 0.5);
	vec.push_back(a);
	vec.push_back(b);
	for (auto X : vec)
		std::cout << X.net_price(10) << std::endl;
	//____________________________________________________
	std::cout << std::endl << std::endl << std::endl;
	//15_29
	std::vector<std::shared_ptr<Quote>> vecsq;
	vecsq.push_back(std::make_shared<Quote>(a));
	vecsq.push_back(std::make_shared<Quote>(b));
	for (auto X : vecsq)
		std::cout << X->net_price(10) << std::endl;
	//结果一样
	//当调用玩push_back之后,存入vector之中的元素就被转换成了shared_ptr<Quote>
	//所以本质上来说,调用的是Quote::net_price,并不会出现多态现象
	//__________________________________________________
	getchar();
}