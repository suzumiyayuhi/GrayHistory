#include"TextQuery.h"
using namespace std;
int main() {
	ifstream in("1.txt");
	TextQuery aaa(in);
	printResult(aaa.query("i"));
	getchar();
	return 0;
}
//16_23
//����Ҫ�����˲�����