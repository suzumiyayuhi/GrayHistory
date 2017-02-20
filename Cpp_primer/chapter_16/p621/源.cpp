#include<iostream>
using namespace std;
//16_53
template<typename T>
ostream& print(ostream &os,const T &d) {
	return os << d<<endl;
}

template<typename T,typename... T1>
void print(ostream &os, const T &data, const T1&... datas) {
	os << data << " ";
	print(os, datas...);
}
//_____________________________________________________
//16_54
//编译出错，提示没有定义<<运算符

//16_55
//会在剩下一个参数的时候转到非可变参数版本的print
int main() {
	print(cout, 1, 2, 3, 4);
	getchar();
	print(cout, "ss", 5);
}