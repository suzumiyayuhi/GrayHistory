#include<iostream>
using namespace std;
template<typename T,typename... Ts>
void foo(T a, Ts...datas) {
	cout << sizeof...(Ts) << endl;
	cout << sizeof...(datas) << endl;
	cout << endl << endl;
}

int main() {
	foo(1, 2.0, "sa", 's');
	foo(1, 2, 3);
	foo(1, 2, "s");
	foo("xx");
	getchar();
}