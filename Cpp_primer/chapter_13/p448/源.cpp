#include<iostream>
#include<memory>
using namespace std;	
int a = 0;

//13_14
//输出相同的值

//13_15
//会改变,用拷贝复制运算符会调用拷贝构造函数

//13_16
//输出结果会被改变
//f接受实参会调用拷贝构造函数，建立一个临时变量
//但若是const类型就不会改变数据结构中的内容

//13_17
struct numbered{
public:

	numbered() { ++a; mysn = a;  }
	numbered(const numbered &b) { ++a; mysn = a; }
	int mysn;
};
void f( numbered a) {
	cout << a.mysn << endl;
}
int main() {
	numbered c, d = c, e = c;
	f(c); f(d); f(e); 
	getchar();
}