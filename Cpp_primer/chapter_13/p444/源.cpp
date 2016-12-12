//13_6
//本质为函数
//当想通过拷贝的方式初始化一个对象，或者对对象进行赋值
//使用赋值运算符号来拷贝一个对象
//类中没有定义编译器会自行生成，也可以自行定义

//13_7
//都成功的使用了拷贝复制运算符
#include"StrBlob.h"
int main() {
	StrBlob a({ "ss","sd" });
	StrBlob b = a;
	StrBlobptr c(a);
	StrBlobptr d;
	d = c;
	getchar();
	return 0;
}

//13_8
struct HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr &a) {
		delete(ps);
		string *newstr = new string(*a.ps);
		ps = newstr;
		i = a.i; 
		return *this; 
	}
private:
	std::string *ps;
	int i;
};
HasPtr::HasPtr(const HasPtr &a) :ps(new std::string(*a.ps)), i(a.i) {}
