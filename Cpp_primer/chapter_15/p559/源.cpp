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
	//���һ��
	//��������push_back֮��,����vector֮�е�Ԫ�ؾͱ�ת������shared_ptr<Quote>
	//���Ա�������˵,���õ���Quote::net_price,��������ֶ�̬����
	//__________________________________________________
	getchar();
}