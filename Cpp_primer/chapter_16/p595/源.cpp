//16_17
//当希望通知编译器一个名字表示类型时必须使用typename

//16_18
//template <typename T, U, typename V> void f1(T, U, V);
template <typename T,typename U, typename V> void f1(T, U, V);
//template <typename T> T f2(int &T);
template <typename T> T f2(T&);
//inline template <typename T> T foo(T, unsigned int*);
template <typename T> T foo(T, unsigned int*);
//template <typename T> f4(T, T);
template <typename T>void f4(T, T);
//typedef char Ctype;
typedef char C;
template <typename Ctype> Ctype f5(Ctype a);

#include<vector>
#include<iostream>
//16_19
using namespace std;
void x1(vector<int> vec) {
	vector<int>::size_type cou = 0;
	for (; cou != vec.size(); ++cou) {
		cout << vec[cou];
	}
}
//___________________________________
//16_20
void x2(vector<int> vec) {
	for (auto beg = vec.begin(); beg != vec.end(); ++beg) {
		cout << *beg;
	}
}
//___________________________________

int main() {
	vector<int> x = { 1,2,3,4 };
	x1(x);
	cout << endl;
	x2(x);
	getchar();
}