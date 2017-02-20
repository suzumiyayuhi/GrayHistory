//16_1
//当需要使用模板函数时,编译器通过使用的实参类型推断编译出特定版本的函数

#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include<string>
using namespace std;
//16_2
template<typename ty1> int compare(ty1 tem1, ty1 tem2) {
	if (tem1 > tem2)
		return 1;
	else
		return -1;
}
//______________________________________

struct Sales_data {
	int a;
	string b;
};
//16_4
template<typename iteratorX, typename ty2>iteratorX findx(iteratorX beg,const iteratorX &end,const ty2 &key) {
	for (; beg != end; ++beg) {
		if (*beg == key)
			return beg;
	}
}
//_________________________________________________
//16_5
template<typename arraytype,unsigned N> void print(arraytype (&arr)[N]) {
	for (auto X : arr)
		cout << X;
}
//16_6
template<typename arrtype, unsigned N> arrtype* begin(arrtype x[N]) {
	return x;
}
template<typename arrtype, unsigned N> arrtype* end(arrtype x[N]) {
	return x+N;
}
//______________________________________________________
//16_7
template<typename arrtype, unsigned N> constexpr unsigned get_size(const arrtype (&arr)[N]) {
	return N;
}
//___________________________________

int main() {
	//16_3 生成后报错
//	Sales_data x, y;
//	int mm = compare<Sales_data>(x, y);
	//_____________________________
	list<string> a = { "ddd", "xxx", "c" };
	vector<int> b = { 1,2,3,4 };
//16_4
	cout << *findx(a.begin(), a.end(), "c") << endl;
	cout << *findx(b.begin(), b.end(), 3) << endl;
//___________________________________
//16_5
	int x[5] = { 1, 2, 3, 4, 5 };
	string y[4] = { "a","x","c","d" };
	print(y);
//_________________________________________
//16_7
	cout << endl << get_size(x) << endl;
	//________________________________
	getchar();
	return 0;
}
//16_8
//迭代器基本不会定义正确的</>