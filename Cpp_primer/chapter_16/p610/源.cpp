//16_42
//val������
//(a)int&
//(b)int&
//(c)int &&
//T������
//(a)int&
//(b)int&
//(c)int
//�ο� http://blog.csdn.net/chxw098/article/details/39500715
//������Щ��һ���ġ�����һ���Խ��Ϊ׼��
//Ҳ�ܿ��� https://github.com/pezy/CppPrimer/blob/master/ch16/ex16.42.43.44.45.46/main.cpp
//��֮��ϵ�ж������Ǻܶ�

//16_43
//int&

//16_44
//��������������ΪTʱ��T����Ϊint/int/int
//��������������Ϊconst T&ʱ��T����Ϊint/int/int

//16_45
//ʹ�����泣��ʱ,TΪint
//ʹ�ñ���ʱ��TΪint&��Ȼ�󱨴�
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