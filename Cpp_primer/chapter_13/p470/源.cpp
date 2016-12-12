//13_39
#include"StrVec.h"
#include"TextQuery.h"
#include"String.h"
using namespace std;

//13_42
void textTextQuery() {
	ifstream in("1.txt");
	TextQuery aaa(in);
	auto temp = aaa.query("i");
	printResult(temp);
	getchar();
}

int main() {
//	textTextQuery();
	String("dd");
	getchar();
}

//13_41
//会造成数据结构中其中一个内存储存空字符