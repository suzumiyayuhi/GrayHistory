#include<iostream>
#include<regex>
using namespace std;

int main() {
	//17_14
	try
	{
	//	regex r1("[[:add:]"); error_ctype
	//	regex r2(":add:]"); error_brack
	//	regex r3("dd)"); error_paren
	}
	catch (const regex_error& e)
	{
		cout << e.what() << "\ncode:" << e.code() << endl;
	}
	getchar();
}18721622175