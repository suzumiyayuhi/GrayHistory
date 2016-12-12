//13_9
//析构函数是一个类型的成员函数
//他会销毁一个对象
//没有自行定义时，编译器会自行定义

//13_10
//StrBlob正常销毁
//StrBlobPtr被销毁时，内存不能完全释放

//13_11
#include<iostream>
using namespace std;
struct HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr&);
	~HasPtr() {}
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

//13_12
//3

struct x {
	x() { cout << "x()" << endl; }
	x(const x& a) { cout << "x(const x& a" << endl; }
	x& operator=(const x& a) { cout << "operator=(const x &a"<<endl; return *this; }
	~x() { cout << "~x()"<<endl; }
};
void ss(x a) {

}
int main() {
	x a, b;
	a = b;
	x c(a);
	ss(a);
	getchar();
	return 0;
}