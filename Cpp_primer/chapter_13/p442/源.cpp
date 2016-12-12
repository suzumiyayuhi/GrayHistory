//13_1
//在函数调用时使用
//还有，拷贝初始化对象
//嗯。。。还有更多。。。可能。。。

//13_2
//必须得是个sales_data引用类型
//否则调用拷贝构造函数会出错
//拷贝实参调用拷贝构造函数，调用拷贝构造函数拷贝实参。。。循环。。。

//13_3
#include"StrBlob.h"
int main() {
	StrBlob a = { "sd","sd" };
	StrBlob b = a;
	StrBlobptr c(a);
	StrBlobptr d = c;
	//好像不会发生什么东西 -_-||
}

//13_4
//Point global;
//Point foo_bar(Point arg){			这里= =
//Point local=arg, *heap = new Point(global);	这里第一个对象初始化= =
//*heap = local;
//Point pa[ 4 ] = {local, *heap};	这里第一个对象初始化。
//return *heap;
//}


//13_5
struct HasPtr{
public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr&);
private:
	std::string *ps;
	int i;
};
HasPtr::HasPtr(const HasPtr &a) :ps(new std::string(*a.ps)), i(a.i) {}
