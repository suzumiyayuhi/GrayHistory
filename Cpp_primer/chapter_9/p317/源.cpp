#include<string>
#include<iostream>
#include<list>
#include<forward_list>
using namespace std;
void X9_31(list<int> &a1) {
	auto x = a1.begin();
	while (x!=a1.end())
	{
		if (*x % 2) 
		{
			x=a1.insert(x, *x);
			++x;
			++x;
		}
		else
		{
			x=a1.erase(x);
		}
	}
}
void X9_31(forward_list<int> &a1) {
	auto x = a1.begin();
	auto y = a1.before_begin();
	while (x != a1.end())
	{
		if (*x % 2)
		{
			x = a1.insert_after(x, *x);
			y = x;
			++x;
		}
		else
		{
			x=a1.erase_after(y);
		}
	}
}
//9_32
//不合法
//编译时，编译器会先处理*iter++的求值，造成第一个传递的实参出错，程序发生混乱。

//9_33
//原先的begin会失效，导致程序出错。

//9_34
//本意是再容器中找到的奇数后插入一个与他数值相同的int对象，并将迭代器指向他之后的一个int对象。
//错误，++iter没有再循环体之中，若容器之中有偶数存在会使程序陷入死循环。
int main() {
	list<int> a1{ 1,2,3,4,5,6,7,8 };
	forward_list<int> a2{ 1,2,3,4,5,6,7,8 };
	X9_31(a1);
	for (auto i : a1)
		cout << i;
	cout << endl;
	X9_31(a2);
	for (auto i : a2)
		cout << i;
	getchar();
	return 0;
}
