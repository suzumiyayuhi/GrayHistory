//#include"the_header.h"
#include"X12_33.h"
//12_32


int main() {
	ifstream in("1.txt");
	TextQuery aaa(in);
	printResult(aaa.query("i"));
	getchar();
	return 0;
}

//12_31
//vector允许有重复，所以在插入新元素必须与原元素比较
//所以set更好
