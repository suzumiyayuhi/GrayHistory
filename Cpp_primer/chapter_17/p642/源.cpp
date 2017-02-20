//17_9
//(a)0....00000100000000000000000000000000
//(b)10101101100101101111000000000000
//(c)取决于输入的数据
#include<bitset>
#include<iostream>
using namespace std;
int main() {
	bitset<32> a(1010101);
	for (int i=0;i<32;++i)
		cout << a[i];
	getchar();
}