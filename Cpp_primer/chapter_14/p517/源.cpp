#include<iostream>
#include<string>
using namespace std;
struct sales_data {
public:
private:
	//14_45
	string bookNo;//转换为stirng,返回bookNo
	double revenue;//转换为double,返回revenue
	//_____________________________________________
};

//14_46
//不该定义,可以通过成员函数来获取值

//14_47
//operator const int();定义了一个转换至const int的转换运算符
//operator int() const;定义了一个转换至int的转换运算符,改运算符不改变对象的值