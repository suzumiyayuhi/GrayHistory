//14_33
//正整数个

#include<iostream>
#include"FunctionObjecth.h"
#include"LikePrintString.h"
#include<vector>
#include"EqualIF.h"
using namespace std;
int main() {
	FunctionObject a(1, 2, 3);
	std::cout << a(4, 5, 6);
	std::cout << std::endl << std::endl;
//	LikePrintString x("");
//	std::cout << x();

	//14_36
	std::vector<std::string> vec;
	LikePrintString like("ss");
	while (true) {
		string temp = like();
		vec.push_back(temp);
		if (temp=="")
			break;
	}
	for (auto pp : vec)
		std::cout << pp;
	//______________________________________________
	std::cout << std::endl << std::endl;
	std::vector<std::string> test = { "aaaa","bbbbb","xxxx" };
	//14_37
	replace_if(test.begin(), test.end(), Equalif("xxxx"),"cccc");
	for (auto PP : test)
 		cout << PP;
	getchar();
}