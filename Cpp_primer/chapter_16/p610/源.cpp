//16_42
//val的类型
//(a)int&
//(b)int&
//(c)int &&
//T的类型
//(a)int&
//(b)int&
//(c)int
//参考 http://blog.csdn.net/chxw098/article/details/39500715
//还是有些不一样的。。。一切以结果为准。
//也能看看 https://github.com/pezy/CppPrimer/blob/master/ch16/ex16.42.43.44.45.46/main.cpp
//总之这系列东西不是很懂

//16_43
//int&

//16_44
//当函数参数声明为T时，T类型为int/int/int
//当函数参数声明为const T&时，T类型为int/int/int

//16_45
//使用字面常量时,T为int
//使用变量时，T为int&，然后报错
#include<iostream>
#include<type_traits>
using namespace std;
static int num;
template <typename T>
void g(T&& val) {
	cout << num++ << ":" << endl;
	std::cout << std::boolalpha;
	cout << "T's type is " << typeid(T).name() << endl;
	cout << "T's type is const? " << is_const<T>::value << endl;
	cout << "Is reference? " << is_reference<T>::value << endl;
	cout << "Is left reference? " << is_lvalue_reference<T>::value << endl;
	cout << "Is right reference? " << is_rvalue_reference<T>::value << endl;
}

int main() {
	int i = 0;
	const int ci = i;
	cout << "i's type is " << typeid(i).name() << endl;
	cout << "ci's type is " << typeid(ci).name() << endl;
	cout << "i * ci's type is " << typeid(i * ci).name() << endl;
	cout << endl << endl;
	g(i);
	g(ci);
	g(i * ci);
	g(3);

	getchar();
}