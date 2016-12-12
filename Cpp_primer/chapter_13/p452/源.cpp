#include<iostream>
using namespace std;
//13_18
struct Employee
{
public:
	string name;
	int ID;
	Employee() { ++counter; ID = counter; }
	static int counter;
private:
	
};
int Employee::counter = 0;
int main() {
	Employee a;
	cout << a.counter;
	getchar();
}
//13_19
//不需要，每个emplyee对象都是不同的

//13_20
//拷贝T，新T的Text和被复制对象的Text指针相同，指向同一文件；result中的string数据相同，size_type则是相同地址
//拷贝Q，key为相同值；Text为相同指针；lines也为相同指针
//销毁时，销毁成员，释放指针

//13_21
//不需要，使用的是智能指针，无论何时都可以安全的释放指针

//13_22
struct HasPtr
{
public:
	HasPtr(const HasPtr &a):xx(a.xx),yy(new string(*a.yy)) { }
	HasPtr& operator=(const HasPtr &a) { 
		auto temp = *a.yy;
		delete yy;
		yy = new string(temp);
		xx = a.xx; 
		return *this;
	}
private:
	int xx;
	string *yy;
};